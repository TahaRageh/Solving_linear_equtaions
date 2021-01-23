#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


// function 1


string properform (string s)
{

  vector <int> number ;
  vector <string> seperated ;
  number.push_back(0);

       for(int i=0;i<s.length();i++)

         {
           if(s.at(i)=='+'||s.at(i)=='-'||s.at(i)=='=')

            {number.push_back(i);}

         }


       for(int n=0;n<number.size()-1;n++)

          {

            seperated.push_back(s.substr(number[n],number[n+1]-number[n])) ;

          }

 seperated.push_back(s.substr(number[number.size()-1]));




// problem of missing +


    for (int k =0 ; k < seperated.size()-1 ; k++ )

    {if (seperated[k].at(0)=='x')  {seperated[k].insert(seperated[k].begin(),'+');} }




  // problem of + and - only

   for (int w = 0; w < seperated.size()-1;w++ )

         {
             if (seperated[w].substr(0,seperated[w].find('x'))=="+")

               {
                 seperated[w].insert(1,"1");
               }


             if (seperated[w].substr(0,seperated[w].find('x'))=="-")

               {
                seperated[w].insert(1,"1");
               }
           }







//all is left

 string t4 ;
 int count = 0;
 for ( int r = 0 ; r < seperated.size()-1 ; r++ )

     {
         count =0;

         for ( int q = 0  ; q < seperated[r].length() ; q++ )

            {
              if (seperated[r].at(q)!='x')
              {count ++;}

            }

           if (count == seperated[r].length())
                 {
                     string t1 = seperated[seperated.size()-1].substr(1);
                     string t2 = seperated[r];
                     float tito = atof (t1.c_str())+ atof(t2.c_str())*-1;
                     ostringstream ss ;
                     ss << tito ;
                     string t3 = ss.str() ;
                     t4 = '=' + t3;

                     seperated.push_back(t4) ;
                     seperated.erase(seperated.end()-2);
                     seperated.erase(seperated.begin()+r);
                     r--;
                 }

     }









   // only one time

 string sss4 ;
 for (int a = 0 ; a < seperated.size()-1 ; a++ )

          {

              for (int p = a+1 ; p < seperated.size()-1 ; p++ )

                 {

                   if (seperated[a].substr(seperated[a].find('x'))== seperated[p].substr(seperated[p].find('x')))

                      {
                         string sss1 = seperated[a].substr(0,seperated[a].find('x'));
                         string sss2 = seperated[p].substr(0,seperated[p].find('x'));
                         float fff1 = atof(sss1.c_str());
                         float fff2 = atof(sss2.c_str());
                         float fff3 = fff1 + fff2;

                         string sss3;
                         ostringstream sb;
                         sb << fff3 ;
                         sss3 = sb.str();

						 if      (fff3 > 0)  { sss4 ='+' + sss3 + seperated[a].substr(seperated[a].find('x')) ;}
						 else if (fff3 < 0)  { sss4 = sss3 + seperated[a].substr(seperated[a].find('x')) ;}
						 else                {seperated.erase(seperated.begin()+a);seperated.erase(seperated.begin()+p);}

                         seperated.erase(seperated.begin()+a);
                         seperated.erase(seperated.begin()+p-1);
                         seperated.insert(seperated.begin()+a,sss4) ;
                         p--;

                      }



                 }

         }




 //alphapetically

          // problem of first element
          string ss = seperated[0].substr(0,seperated[0].find('x'));
          float ff =  atof(ss.c_str());

		  if ( seperated[0].at(0) != '+')
          {
           seperated[0]= '+'+ seperated[0]  ;
          }




    for(int m=0; m<seperated.size()-1; m++)

      {

         for (int k=m+1; k<seperated.size()-1; k++)
            {

                string s1 = seperated[k].substr(seperated[k].find('x')+1);
                string s2 = seperated[m].substr(seperated[m].find('x')+1);
                float f1 =  atof(s1.c_str());
                float f2 = atof(s2.c_str());

                if (f1<f2 )

                 { iter_swap(seperated.begin() + m , seperated.begin() +k ); }

                  /*
				   string Temp=seperated[m];
				   seperated[m]=seperated[k];
				   seperated[k]=Temp;}
                   */

            }
      }


/*

 for(int z=0;z<seperated.size();z++)
 cout<<seperated[z]<<endl;



*/


  string newequ = "" ;
  for (int t=0;t<seperated.size();t++)

      {

       newequ =  newequ + seperated[t];

      }


    //cout << newequ ;

 if (newequ.at(0) == '+' ) { newequ.erase(0,1);}



return newequ ;



}




// function 2 with sending string

vector <float> coefficients (string s)

{

 vector <int> number ;
  vector <string> seperated ;
  number.push_back(0);

       for(int i=0;i<s.length();i++)

         {
           if(s.at(i)=='+'||s.at(i)=='-'||s.at(i)=='=')

            {number.push_back(i);}

         }


       for(int n=0;n<number.size()-1;n++)

          {

            seperated.push_back(s.substr(number[n],number[n+1]-number[n])) ;

          }


   seperated.push_back(s.substr(number[number.size()-1]));


// problem of first coefficient of first element if one

      if (seperated[0].substr(0,1)=="x") {seperated[0].insert(0,"1");}


  // problem of + and - only

   for (int w = 0; w < seperated.size()-1;w++ )

         {
             if (seperated[w].substr(0,seperated[w].find('x'))=="+")

               {
                 seperated[w].insert(1,"1");
               }


             if (seperated[w].substr(0,seperated[w].find('x'))=="-")

               {
                seperated[w].insert(1,"1");
               }
           }



         vector <string> Ahmed ;
        for (int ut =0 ; ut < seperated.size()-1 ; ut ++)

          {

            string qw = seperated[ut].substr(0,seperated[ut].find('x'));

            Ahmed.push_back(qw);

          }


        if (seperated[seperated.size()-1].at(0)=='=')
          {
             string constant =  seperated[seperated.size()-1].substr(1);
             Ahmed.push_back(constant);
           }

   vector <float> coffes;
       for (int re =0 ; re < Ahmed.size(); re ++)
         {

           float qww = atof(Ahmed[re].c_str()) ;
           coffes.push_back(qww);
         }

     return coffes ;
}

/*

// function 2 with sending vector

vector <float> coefficients ( vector <string> seperated )

  {
         vector <string> Ahmed ;
        for (int ut =0 ; ut < seperated.size()-1 ; ut ++)

          {

            string qw = seperated_two[ut].substr(0,seperated_two[ut].find('x'));

            Ahmed.push_back(qw);

          }


        if (seperated_two[seperated_two.size()-1].at(0)=='=')
          {
             string constant =  seperated_two[seperated_two.size()-1].substr(1);
             Ahmed.push_back(constant);
           }


       vector <float> coffes;
       for (int re =0 ; re < Ahmed.size(); re ++)
         {

           float qww = atof(Ahmed[re].c_str()) ;
           coffes.push_back(qww);
         }

     return coffes ;
   }


   */


//function 3 with sending string



vector <string> variables (string s)

 {

   vector <int> number ;
   vector <string> seperated ;
   number.push_back(0);

       for(int i=0;i<s.length();i++)

         {
           if(s.at(i)=='+'||s.at(i)=='-'||s.at(i)=='=')

            {number.push_back(i);}

         }


       for(int n=0;n<number.size()-1;n++)

          {

            seperated.push_back(s.substr(number[n],number[n+1]-number[n])) ;

          }


// problem of first coefficient of first element if one

    if (seperated[0].substr(0,1)=="x") {seperated[0].insert(0,"1");}




  // problem of + and - only

   for (int w = 0; w < seperated.size()-1;w++ )

         {
             if (seperated[w].substr(0,seperated[w].find('x'))=="+")

               {
                 seperated[w].insert(1,"1");
               }


             if (seperated[w].substr(0,seperated[w].find('x'))=="-")

               {
                seperated[w].insert(1,"1");
               }
           }



    vector <string> Ahmed ;

        for (int ut =0 ; ut < seperated.size() ; ut ++)

          {

             string qw = seperated[ut].substr(seperated[ut].find('x'));

             Ahmed.push_back(qw);

          }

    return Ahmed ;

   }







/*
//function 3 with sending vector

    vector <string> variables ( vector <string> seperated_two )

   {

        vector <string> Ahmed ;

        for (int ut =0 ; ut < seperated_two.size()-1 ; ut ++)

          {

             string qw = seperated_two[ut].substr(seperated_two[ut].find('x'));

             Ahmed.push_back(qw);

          }

        return Ahmed ;
   }


*/







int main()
{



int n ;
cin >> n;
cin.ignore();



string ww ;
vector <string> equations ;


 for(int yy = 0 ; yy < n ; yy ++ )
  {
    getline(cin,ww);
    equations.push_back(ww);

  }


// proper form

for(int qq=0;qq<equations.size();qq++)
{equations[qq]=properform(equations[qq]); }




/*

for(int zz=0;zz<equations.size();zz++)
 {cout<<equations[zz]<<endl;}

*/




// num_vars


vector <string> var ;
var = variables(equations[0]);


vector <string> tata ;

for (int ii = 1 ; ii< equations.size() ; ii++)
{

tata = variables(equations[ii]);
var.insert(var.end(),tata.begin() , tata.end());
}

// remove similar

sort(var.begin(), var.end());
var.erase(unique(var.begin(), var.end()), var.end());









// declare 2D vector

vector< vector<float> > matrix ;
// make new row (arbitrary example)
vector <float> tempo ;
vector <float> tio  ;
for (int j =0; j < equations.size() ; j++)
{
    tio =  coefficients(equations[j]) ;

   for ( int i = 0 ; i< tio.size() ;i++ )
    {

        tempo.push_back(tio[i]);
    }

 matrix.push_back(tempo);
 tempo.clear();

}







// tasfeeeeeer

vector <string> tyt ;
int count = 0 ;


for (int ios = 0 ; ios < equations.size() ;ios++ )
 {
    tyt = variables( equations[ios] ) ;


   for (int i = 0 ; i < var.size() ; i++)
       {
          for (int joj = 0 ; joj < tyt.size() ; joj++)
           {
            if (var[i]!=tyt[joj]){count++;}
           }

         if ( count == tyt.size() ) { matrix[ios].insert(matrix[ios].begin()+i,0); }
          count =0 ;
      }
tyt.clear();

 }






















/*


for (int i = 0;i < matrix.size(); i++)
{
    for (int j =0 ; j < matrix[i].size() ; j++)
    {
        cout << matrix[i][j];
        cout << '\t';
    }
    cout <<endl ;
}

*/




 string operation ;

do
{
  getline(cin,operation);


if (operation == "num_vars" )
{
cout << var.size()<< endl;
}





if (operation.substr(0,8) == "equation")
{
   string nun = operation.substr(9);


   float nu = atof(nun.c_str());

   cout << equations[nu-1]<< endl;

}



if (operation.substr(0,6) == "column")
{
    string rt = operation.substr(8);

     float gym = atof(rt.c_str());

     for (int y = 0 ; y < equations.size() ; y++)

    { cout<< matrix[y][gym] << endl ;}

}




if (operation.substr(0,3)== "add")
{

   string fi = operation.substr(4,1) ;
   string se = operation.substr(6,1) ;

   float first  = atof(fi.c_str())-1 ;
   float second = atof(se.c_str())-1 ;


   vector <float> add ;
   for (int i = 0 ; i < matrix[first].size() ;i++)

   {add.push_back( matrix[first][i] + matrix[second][i] ) ; }
/*
   for (int j = 0 ; j < add.size() ; j++)

   {cout << add[j]<< endl;}
*/

   vector <string> add_string ;

   for (int j = 0 ; j < add.size() ; j++)
    {

      string str ;
      ostringstream ss;
      ss << add[j] ;
      str = ss.str();
      add_string.push_back(str) ;
    }


  // problem of missing +


    for (int k =0 ; k < add.size()-1 ; k++ )

    {if (add[k]>0)  { add_string[k].insert(add_string[k].begin(),'+');} }

    vector <string> seperated_add ;
    for (int i = 0 ; i < var.size() ; i++ )
    {
    seperated_add.push_back( add_string[i] + var[i] ) ;
    }

    // last of =
    seperated_add.push_back("=" + add_string[add_string.size()-1]) ;






    string newequ = "" ;
     for (int t=0;t<seperated_add.size();t++)

      {
       newequ =  newequ + seperated_add[t];
      }




 if (newequ.at(0) == '+' ) { newequ.erase(0,1);}


cout << newequ<<endl ;

/*
    for (int j = 0 ; j < add_string.size() ; j++)
   {cout << add_string[j]<< endl;}

   */
}






if (operation.substr(0,8)== "subtract")
{

   string fi = operation.substr(9,1);
   string se = operation.substr(11,1);
   float first  = atof(fi.c_str())-1;
   float second = atof(se.c_str()) -1 ;


   vector <float> subtract;

   for (int i = 0 ; i < matrix[first].size() ;i++)

   {subtract.push_back( matrix[first][i] - matrix[second][i] ) ; }
/*
   for (int j = 0 ; j < subtract.size() ; j++)

   {cout << subtract[j]<< endl;}
*/

   vector <string> subtract_string ;

   for (int j = 0 ; j < subtract.size() ; j++)
    {

      string str ;
      ostringstream ss;
      ss << subtract[j] ;
      str = ss.str();
      subtract_string.push_back(str) ;
    }


 // problem of missing +


    for (int k =0 ; k < subtract.size()-1 ; k++ )

    {if (subtract[k]>0)  { subtract_string[k].insert(subtract_string[k].begin(),'+');} }

    vector <string> seperated_subtract ;
    for (int i = 0 ; i < var.size() ; i++ )
    {
    seperated_subtract.push_back( subtract_string[i] + var[i] ) ;
    }

    // last of =
    seperated_subtract.push_back("=" + subtract_string[subtract_string.size()-1]) ;






    string newequ = "" ;
     for (int t=0;t<seperated_subtract.size();t++)

      {
       newequ =  newequ + seperated_subtract[t];
      }




 if (newequ.at(0) == '+' ) { newequ.erase(0,1);}


cout << newequ << endl ;

/*

    for (int j = 0 ; j < subtract_string.size() ; j++)
   {cout << subtract_string[j]<< endl;}
   */
}





if (operation.substr(0,10)== "substitute")
{

   string xi = operation.substr(12,1);
   float xu = atof(xi.c_str())-1 ;

   string fi = operation.substr(14,1);
   string se = operation.substr(16,1);
   float first  = atof(fi.c_str())-1;
   float second = atof(se.c_str()) -1 ;

   float fe = matrix[first][xu];
   float sec = matrix[second][xu];

   vector <float> new_coeff ;

   for (int z =0 ; z < matrix[0].size() ; z++ )

   { new_coeff.push_back( matrix[first][z]*sec - matrix [second][z]*fe ) ;  }





   vector <string> substitute_string ;

   for (int j = 0 ; j < new_coeff.size() ; j++)
    {

      string str ;
      ostringstream ss;
      ss << new_coeff[j] ;
      str = ss.str();
      substitute_string.push_back(str) ;
    }


  // problem of missing +


    for (int k =0 ; k < new_coeff.size()-1 ; k++ )

    {if (new_coeff[k]>0)  {substitute_string[k].insert(substitute_string[k].begin(),'+');} }


    vector <string> seperated_substitute ;

    for (int i = 0 ; i < var.size() ; i++ )
    {
    seperated_substitute.push_back( substitute_string[i] + var[i] ) ;
    }

    seperated_substitute.erase (seperated_substitute.begin()+xu);
    // last of =
    seperated_substitute.push_back("=" + substitute_string[substitute_string.size()-1]) ;






    string newequ = "" ;
     for (int t=0;t<seperated_substitute.size();t++)

      {
       newequ =  newequ + seperated_substitute[t];
      }



 if (newequ.at(0) == '+' ) { newequ.erase(0,1);}


cout << newequ << endl ;


/*
   for(int r = 0 ; r <new_coeff.size() ; r++ )
   {cout <<new_coeff[r] <<endl;}
*/
}




if (operation == "D")
  {
    for (int i = 0;i < matrix.size(); i++)
     {
        for (int j =0 ; j < matrix[i].size()-1 ; j++)
         {
        cout << matrix[i][j];
        cout << '\t';
         }
    cout <<endl ;
    }
  }






 if (operation.substr(0,3) == "D x")
  {

    string xi = operation.substr(3,1);
    float xu = atof(xi.c_str())-1 ;




vector< vector<float> > new_matrix ;

vector <float> tempo ;

for (int j =0; j < matrix.size() ; j++)
{

   for ( int i = 0 ; i< matrix[j].size() ;i++ )
    {
        tempo.push_back( matrix[j][i] );
    }

 new_matrix.push_back(tempo);
 tempo.clear();

}



 for (int i = 0;i < new_matrix.size(); i++)
     {

        new_matrix[i][xu] = new_matrix[i][new_matrix[i].size()-1] ;
    }





    for (int i = 0;i < new_matrix.size(); i++)
     {
        for (int j =0 ; j < new_matrix[i].size()-1 ; j++)
         {
        cout << new_matrix[i][j];
        cout << '\t';
         }
    cout <<endl ;
    }






  }








}

while (operation != "quit") ;





return 0;
}
