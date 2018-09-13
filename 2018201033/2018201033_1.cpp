#include<bits/stdc++.h>

using namespace std;

class mybiginteger
{
     private: 
        int globalcarry; //to check carray generated at last, while adding 1 to 9's compliment
        int subflag;  //to show currently we are doing substraction
     public: 
           

        string take9scomplement(string str, int size)
        {
            //cout<<"\nstring in 10th complement: "<<str<<"size"<<size;
            for(int i=0;i<size;i++)
            {
              str[i]=(9 -(str[i]-'0') + '0');
            }
            return str;
        }

        string addTwoLargeNumber(string s1,string s2)
        {
            
            string ans;
            if(subflag!=1)
            {
               s1.erase(0, s1.find_first_not_of('0'));
               s2.erase(0, s2.find_first_not_of('0'));  
            }

            //cout<<"\ns1 : "<<s1<<"\ns2 : "<<s2<<endl;
            if(s1.length()==0 && s2.length()==0)
                return "0";
            
            int size1=s1.length();
            int size2=s2.length();
            
            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());

            //cout<<"\ns1 : "<<s1<<"\ns2 : "<<s2;
            int i,carry=0;
            globalcarry=0;

            int anssize = (size1 >= size2)? size1 : size2;
            ans.resize(anssize);
            int minsize = (size1 <= size2)? size1 : size2;

            for(i=0;i<minsize;i++)
            {
                int temp=(s1[i]-'0')+(s2[i]-'0') + carry;
                ans[i] = (temp%10)+'0';
                carry = temp/10;
            }
          
            if(i<size1)
            {
    
                for(int k=i;k<size1;k++)
                {
                  int temp=(s1[k]-'0') + carry;
                  ans[k] = (temp%10)+'0';
                  carry = temp/10;
                }
            }
            else{

                for(int k=i;k<size2;k++)
                {
                  int temp=(s2[k]-'0') + carry;
                  ans[k] = (temp%10)+'0';
                  carry = temp/10;
                }
            }

            if(carry)
            {
               globalcarry=1;
            }

            if(subflag!=1)
            {
              while(carry)
              {
                  int rem= carry%10;
                  carry= carry/10;
                  anssize++;
                  ans.resize(anssize);
                  ans[anssize-1] = rem + '0';
                 
              }
            }
            
            reverse(ans.begin(), ans.end());
            
            return (ans);
        }

        string subTwoLargeNumber(string s1,string s2)
        {
            int swapflag=0;
            //cout<<"\nsub : "<<" s1 : "<<s1<<" s2 : "<<s2<<endl;
            string temp;
            subflag=1;
            s1.erase(0, s1.find_first_not_of('0'));
            s2.erase(0, s2.find_first_not_of('0'));
            if(s1.length()==0 && s2.length()==0)
                return "0";
            if(s1.length()>s2.length())
            {
                temp=s1;
                s1=s2;
                s2=temp;
                swapflag=1;
            }
            //cout<<"\ns1 : "<<s1<<"\ns2 : "<<s2<<endl;
            s2=take9scomplement(s2,s2.length());
            s2 = addTwoLargeNumber(s2,"1");
            //cout<<"\nAfter s2 : "<<s2<<endl;
            string ans = addTwoLargeNumber(s1,s2);
           //cout<<"\nans : "<<ans<<endl;
            if(!globalcarry)
            {
                 ans = take9scomplement(ans,ans.length());
                 ans = addTwoLargeNumber(ans,"1");
                 if(!swapflag)
                    ans = "-"+ans;
            }
            subflag=0;

            ans.erase(0, ans.find_first_not_of('0'));
            if(ans.length()==0)
            {
                return "0";
            }
            else
                return ans;
        
        }


        string mulTwoLargeNumber(string s1, string s2)
        {
            s1.erase(0, s1.find_first_not_of('0'));
            s2.erase(0, s2.find_first_not_of('0'));
            if(s1.length()==0 || s2.length()==0)
                return "0";
            int len1=s1.length();
            int len2=s2.length();
            if(len1 < len2)
            {
                string temp1=s1;
                s1=s2;
                s2=temp1;
            }
            reverse(s1.begin(), s1.end());
            //cout<<"\ns1 : "<<s1<<" s2 : "<<s2<<endl;
            
            string temp;
            string ans;
            temp.resize(len1*len2 + 1);
            ans.resize(len1*len2 + 1);

            for(int i=0;i<s2.length();i++)
            {
                int k,carry=0;
                //cout<<"anslngth : "<<ans.length();
                for(int i=0;i<ans.length();i++)
                {
                   ans[i]='0';
                }

                k= s2.length()-i-1;

                for(int j=0;j<s1.length();j++)
                {
                    int temp=(s2[i]-'0')*(s1[j]-'0') + carry;
                    //cout<<"\ntemp : "<<temp;
                    ans[k] = (temp%10)+'0';
                    carry = temp/10;
                    k++;
                }
                //cout<<"\n ans : "<<ans<<" carray : "<<carry<<endl;
                while(carry)
                {
                    int rem= carry%10;
                    carry= carry/10;
                    ans[k] = rem + '0';
                    k++;
                }
                reverse(ans.begin(), ans.end());
                //cout<<"\n***ans : "<<ans;
                //cout<<"\n***temp : "<<temp;
                string addans;

                if(i==0)
                    addans=ans;
                else
                    addans=addTwoLargeNumber(ans,temp);

                //cout<<"\nAddAns : "<<addans<<endl;

                temp=addans;

                //cout<<"\n Ans End  : "<<temp<<endl;
            }

            //cout<<"\nMultiplication : "<<ans;
             temp.erase(0, temp.find_first_not_of('0'));
             if(temp.length()==0)
             {
                return "0";
             }
             else
                return temp;

        }

        string addition(string s1,string s2)
        {
            int ch1,ch2;
            ch1=s1[0];
            ch2=s2[0];
            if(ch1=='-' && ch2=='-') 
            {
                string temp1=s1.substr(1);
                string temp2=s2.substr(1);
                return "-"+addTwoLargeNumber(temp1,temp2);
            }
            else if(ch1=='-' && ch2!='-')
            {
                  string temp1=s1.substr(1);
                  return subTwoLargeNumber(s2,temp1);
            }
            else if(ch1!='-' && ch2=='-')
            {
                  string temp2=s2.substr(1);
                  return subTwoLargeNumber(s1,temp2);
            }
            else
            {
                  return addTwoLargeNumber(s1,s2);
            }
        }

        string subtraction(string s1,string s2)  //s1 - s2;
        {
            int ch1,ch2;
            ch1=s1[0];
            ch2=s2[0];
            if(ch1=='-' && ch2=='-') 
            {
                string temp1=s1.substr(1);
                string temp2=s2.substr(1);
                return subTwoLargeNumber(temp2,temp1);
            }
            else if(ch1=='-' && ch2!='-')
            {
                  string temp1=s1.substr(1);
                  return "-"+addTwoLargeNumber(temp1,s2);
            }
            else if(ch1!='-' && ch2=='-')
            {
                  string temp2=s2.substr(1);
                  return addTwoLargeNumber(s1,temp2);
            }
            else  // + op + 
            {
                  return subTwoLargeNumber(s1,s2);
            }
        }

        string multiplication(string s1,string s2)  //s1 - s2;
        {
            int ch1,ch2;
            ch1=s1[0];
            ch2=s2[0];
            if(ch1=='-' && ch2=='-') 
            {
                string temp1=s1.substr(1);
                string temp2=s2.substr(1);
                return mulTwoLargeNumber(temp1,temp2);
            }
            else if(ch1=='-' && ch2!='-')
            {
                  string temp1=s1.substr(1);
                  return "-"+mulTwoLargeNumber(temp1,s2);
            }
            else if(ch1!='-' && ch2=='-')
            {
                  string temp2=s2.substr(1);
                  return "-"+mulTwoLargeNumber(s1,temp2);
            }
            else  // + op + 
            {
                  return mulTwoLargeNumber(s1,s2);
            }
        }

        string division(string s1,string s2)
        {
            s1.erase(0, s1.find_first_not_of('0'));
            s2.erase(0, s2.find_first_not_of('0'));
            if(s1.length()==0)
                  return "0";
            else if(s2.length()==0){
                  return "0";
            }
            if(s2.length()>s1.length())
            {
              return "0";
            }
            string count = "0";
            string ans = s1;
            while(true)
            {
                  ans = subTwoLargeNumber(ans,s2);

                  if(ans[0]!='-')
                  {
                     count= addTwoLargeNumber(count,"1");
                  }
                  else{
                    break;
                  }
            }
            return count;
        }

        string GCDCalculate(string s1, string s2)
        {
            s1.erase(0, s1.find_first_not_of('0'));
            s2.erase(0, s2.find_first_not_of('0'));
            
            if(s1.length() == 0)
                return s2;

            string dd = division(s2,s1);
            //cout<<"dd : "<<dd<<endl;
            string mm = mulTwoLargeNumber(s1,dd);
            //cout<<"Mm : "<<mm<<endl;
            string rem = subTwoLargeNumber(s2,mm);
            //cout<<"Rem : "<<rem<<endl;
            //cout<<"s1 : "<<s1<<endl;

            return GCDCalculate(rem,s1);  
        }

        string GCD1(string s1,string s2)
        {
            
            return GCDCalculate(s1,s2);
        }
};

int main()
{
    int test;
    cin>>test;
    
    while(test--)
    {
      string s1,s2;
      int choice;
      cin>>s1;
      cin>>s2;
      mybiginteger obj1;
      cin>>choice;
        switch(choice)
        {
            case 1:
               cout<<obj1.addition(s1,s2)<<endl;
                break;
            case 2:
                cout<<obj1.subtraction(s1,s2)<<endl;
                break;
            case 3:
               cout<<obj1.multiplication(s1,s2)<<endl;
                break;
            case 4:
                cout<<obj1.division(s1,s2)<<endl;
                break;
            case 5:
               cout<<obj1.GCD1(s1,s2)<<endl;
                break;
         
        }
    }

}