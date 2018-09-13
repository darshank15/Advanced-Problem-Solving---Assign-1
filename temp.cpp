 // int checklarge(mybiginteger obj)
      // {
      //       if (obj.len1 > obj.len2)
      //           return false;
      //       if (obj.len2 < obj.len1)
      //         return false;
         
      //       for (int i=0; i<obj.len1; i++)
      //       {
      //         if (obj.num1[i] < obj.num2[i])
      //             return true;
      //         else if (obj.num1[i] > obj.num2[i])
      //             return false;  
      //       }
            
      // }



// void substract()
      // {
      //     int i,borrow=0;
      //     int flagset=0;
      //     anssize = (size1>=size2)? size1 : size2;
      //     InitialisedResultArrayZero();
      //     int minsize = (size1<=size2)? size1 : size2;
      //     //cout<<"size1>=size2";
      //     for(i=0;i<minsize;i++)
      //     {
      //         int temp=(array1[i]-borrow)-array2[i];
      //         if(temp>=0)
      //         {
      //             ansArray[i]=temp;
      //             borrow=0;
      //         }
      //         else{
      //             ansArray[i] = 10 + temp;
      //             borrow = 1;
      //         }
      //     }
      //     cout<<"\nafter equal size : "<<borrow<<endl;
      //     if(i<size1)
      //     {
      //         cout<<"\nsub size1 remaining : ";
      //         for(int k=i;k<size1;k++)
      //         {
      //           int temp=(array1[k]-borrow);
      //           if(temp>=0)
      //             {
      //                 ansArray[k]=temp;
      //                 borrow=0;
      //             }
      //             else{
      //                 ansArray[k] = 10 + temp;
      //                 borrow = 1;
      //             }
      //         }
      //     }
      //     else{
      //         cout<<"\nsub size2 remaining : ";

      //         for(int k=i;k<size2;k++)
      //         {
      //             ansArray[k]= (10 - array2[k])-borrow;
      //             borrow=-1;
      //             cout<<"\nsub size2 remaning ansArray[i]" <<ansArray[i];
      //         }
      //     }
      //     cout<<"\nfinally borrow : "<<borrow<<endl;
      //     if(borrow == 1)
      //     {
      //        flagset=1;
      //        for(int i=0;i<anssize;i++)
      //        {
      //             ansArray[i] = 9 - ansArray[i];
      //        }
      //     } 
      //     if(flagset)
      //     {
      //       cout<<"\nSub  : -";
      //       showAnswer();
      //     }
      //     else
      //     {
      //       cout<<"\nSub : ";
      //       showAnswer(); 
      //     }
      // }



string mulTwoLargeNumber(string s1, string s2)
        {
            s1.erase(0, s1.find_first_not_of('0'));
            s2.erase(0, s2.find_first_not_of('0'));
            int len1=s1.length();
            int len2=s2.length();
            if(len1 < len2)
            {
                string temp1=s1;
                s1=s2;
                s2=temp1;
            }
            reverse(s1.begin(), s1.end());
            //reverse(s2.begin(), s2.end());
            cout<<"\ns1 : "<<s1<<" s2 : "<<s2<<endl;
            
            string temp;
            string ans;
            temp.resize(len1*len2);
            ans.resize(len1*len2);

            for(int i=0;i<s2.length();i++)
            {
                int k,carry=0;
                cout<<"anslngth : "<<ans.length();
                for(int i=0;i<ans.length();i++)
                {
                   ans[i]='0';
                }
                k= s2.length()-i-1;
                cout<<"\nadding zero ans : "<<ans<<endl;
                for(int j=0;j<s1.length();j++)
                {
                    int temp=(s2[i]-'0')*(s1[j]-'0') + carry;
                    cout<<"\ntemp : "<<temp;
                    ans[k] = (temp%10)+'0';
                    carry = temp/10;
                    k++;
                }
                cout<<"\n ans : "<<ans<<" carray : "<<carry<<endl;
                while(carry)
                {
                    int rem= carry%10;
                    carry= carry/10;
                    ans[k] = rem + '0';
                    k++;
                }
                for(int i=0;i<ans.length();i++)
                {
                   cout<<"-------===> "<<ans[i]<<endl;
                }
                cout<<"&&&&&&&&&&&&& : "<<ans<<endl;
                reverse(ans.begin(), ans.end());
                cout<<"\n***ans : "<<ans;
                cout<<"\n***temp : "<<temp;
                for(int i=0;i<ans.length();i++)
                {
                  cout<<"\n ----> "<<ans[i];
                }
                string addans;

                if(i==0)
                    addans=ans;
                else
                    addans=addTwoLargeNumber(ans,temp);
                
                cout<<"\nAddAns : "<<addans<<endl;

                temp=ans;
                ans=addans;

                cout<<"\nans : "<<ans<<endl;
                cout<<"\ntemp : "<<temp<<endl;
            }

            cout<<"\nMultiplication : "<<ans;
            return ans;
}


Enter first number :00000

Enter second number :00001

sum : 00001
Substraction : -1
Multiplication : 0

