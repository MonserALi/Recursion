#include <bits/stdc++.h>
using namespace std;

///1. factorial of a number
int factorial(int n)
{
    if(n<=1) return 1;
    return n*factorial(n-1);
}


///2. power of a number
int power(int x,int y)
{
    if(y==0)
    {
        return 1;
    }
    return x*power(x,y-1);
}

///3. nth fibonacci number
int fibonacci(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;

    return fibonacci(n-1)+fibonacci(n-2);
}

///4. palindrom or not for a string
string removeSpaceandCase(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ')
        {
            s.erase(s.begin()+i);
        }
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i]+=32;
        }
    }
    return s;
}
bool isPalindromForString(string s, int l, int h)
{
    if(s[l]!=s[h]) return 0;
    if(l>=h) return true;

    return isPalindromForString(s,l+1, h-1);
}

/// 5. print all even number from a given range
void printAllEvenInARange(int x, int y)
{
    if(x>y) return;
    if(x%2==0)
    {
        cout<<x<<" ";
    }
    printAllEvenInARange(x+1, y);
}

/// 6. print an array in given order
void printArrayInGivenOrder(int *arr, int n)
{
    if(n<0) return;

    printArrayInGivenOrder(arr,n-1);
    cout<<arr[n]<<" ";
}

/// 7. print an array in reverse order
void printArrayInReverseOrder(int *arr, int n)
{
    if(n<0) return;

    cout<<arr[n]<<" ";
    printArrayInReverseOrder(arr,n-1);
}

/// 8. sum of all the elements of an array
int sumOfAllElement(int *arr,int n)
{
    if(n==0) return arr[0];
    return arr[n] + sumOfAllElement(arr,n-1);
}

/// 9. product of all the elements of an array
int productOfAllElement(int *arr,int n)
{
    if(n==0) return arr[0];
    return arr[n] * productOfAllElement(arr,n-1);
}

///10. find maximum from an array
int findMax(int *arr, int n)
{
    if(n==0) return arr[n];
    return max(arr[n],findMax(arr,n-1));
}

/// 11. find the minimum from an array
int findMin(int *arr, int n)
{
    if(n==0) return arr[0];
    return min(arr[n],findMin(arr,n-1));
}

/// 12. find the average of an array
double average(int *arr, int n)
{
    if(n==1) return arr[n-1];
    return (average(arr,n-1)*(n-1) + arr[n-1])/n;
}

/// 13 print all even  values
void printOddElements(int *arr, int n)
{
    if(n<0) return ;

    printOddElements(arr,n-1);
    if(arr[n]%2)cout<<arr[n]<<" ";

}

/// 14 print all prime from an array
bool isPrime(int n, int d)
{
    if(n<2) return false;
    if(d==1) return true;
    if(n%d==0) return false;

    return isPrime(n,d-1);
}
void printAllPrime(int *arr, int n)
{
    if(n<0) return;
    printAllPrime(arr,n-1);
    if(isPrime(arr[n],arr[n]-1))
        cout<<arr[n]<<" ";
}

///15 count odd and even in an array
int countOdd(int *arr, int n, int &cnt)
{
    if(n==0  && arr[n]%2) return cnt+=1;
    if(n==0  && arr[n]%2==0) return cnt;
    if(arr[n]%2) cnt+=1;
    countOdd(arr,n-1,cnt);
}

/// 16 count the number of prime in an array
int countPrime(int *arr, int n, int &cnt)
{
    if(n==0  && isPrime(arr[n],arr[n]-1)) return cnt+=1;
    if(n==0  && !(isPrime(arr[n],arr[n]-1))) return cnt;
    if(isPrime(arr[n],arr[n]-1)) cnt+=1;
    countPrime(arr,n-1,cnt);
}

///17 maximum element from an 2d array
const int r = 3;
const int c = 3;

int findMaxFrom2D(int arr[][c],int i, int j)  /// to  avoid complexity assume the column is always 3
{
    if(i==r-1 && j==c-1)
    {
        return arr[i][j];
    }
    if(j<c-1)
    {
        return(max(arr[i][j], findMaxFrom2D(arr,i,j+1)));
    }
    else if(i<r-1)
    {
        return (max(arr[i][j],findMaxFrom2D(arr,i+1,0)));
    }

}

///18 find the number of prime of a 2d array
int findNumberOfPrimeIn2D(int arr[][c], int i, int j, int &cnt){
    if(i==r-1 && j==c-1){
        if(isPrime(arr[i][j],arr[i][j]-1)) return cnt+=1;
        if (!(isPrime(arr[i][j],arr[i][j]-1))) return cnt;
    }
    if(isPrime(arr[i][j],arr[i][j]-1)) return cnt+=1;

    if(j<c-1)
    {
        findMaxFrom2D(arr,i,j+1);
    }
    else if(i<r-1)
    {
        findMaxFrom2D(arr,i+1,0);
    }
}

///19 print the series and find the sum of a series up to nth term
void series1(int n, int &sum,int f){
    if(f==n){
        cout<<n<<endl;
        sum+=n;
        return;
    }
    sum+=f;
    cout<<f<<" + ";
    series1(n,sum,f+1);

}
void series2(int n, int &sum, int f){
    if(f==n){
        cout<<n<<"^"<<2<<endl;
        sum+=(power(n,2));
        return;
    }
    sum+=(power(f,2));
    cout<<f<<"^"<<2<<" + ";
    series2(n,sum,f+1);
}
void series3(int n, int &sum, int f, int s){
    if(n==f){
        cout<<n<<"*"<<s<<endl;
        sum+=(n*s);
        return;
    }
    sum+=(f*s);
    cout<<f<<"*"<<s<<" + ";
    series3(n,sum,f+1,s+2);
}
void series4(int n, int &sum, int i, int f, int s){
    if(n==i){
        cout<<f<<"*"<<s<<endl;
        sum+=(f*s);
        return;
    }
    sum+=(f*s);
    cout<<f<<"*"<<s<<" + ";
    series4(n,sum,i+1,f*2,s+2);
}
void series5(int n, int &sum, int i, int f, int s, int l){
    if(n==i){
        cout<<f<<"*"<<s<<"*"<<l<<endl;
        sum+=(f*s*l);
        return;
    }
    sum+=(f*s*l);
    cout<<f<<"*"<<s<<"*"<<l<<" + ";
    series5(n,sum,i+1,f*2,s+2,l-1);
}

/// 20. find the gcd of two positive integer
int GCD(int x, int y){
    if(y==0){
        return x;
    }
    return GCD(y,x%y);
}

/// 21. find the lcm of two positive integer
int LCM(int a, int b)
{
    static int m = 0;
    m += b;
    if((m % a == 0) && (m % b == 0))
    {
        return m;
    }
    else
    {
        LCM(a, b);
    }
}
///22 count total number of digit in an integer
int countNumberOfDigit(int n){
    if(n==0) return 0;
    return  1 + countNumberOfDigit(n/10);
}

///23 calculate the sum of all digit
int calculateSumOfAllDigit(int n){
    if(n==0) return 0;
    return n%10 + calculateSumOfAllDigit(n/10);
}

/// 24 palindrome or not for number
int reverseNum(int num, int revNum){
    if(num == 0) return revNum;
    revNum = revNum*10;
    revNum+= num%10;

    return reverseNum(num/10, revNum);
}
bool isPalindromForNumber(int n){
    if(n==reverseNum(n,0)){
        return true ;
    }
    return false;
}

/// 25 all possible subset of a set of n elements
void allSubSet(string str, int index, string curr)
{
    int n = str.length();

    if (index == n){
        return;
    }

    if(curr.length()==0) cout<<"NULL"<<endl;
    else{
        cout << curr << endl;
    }


    for (int i = index + 1; i < n; i++) {

        curr += str[i];
        allSubSet(str, i, curr);
        curr.erase(curr.size() - 1);
    }
    return;
}
/// 27 binary search recursive algorithm

int binarySearch(int *arr, int key, int l, int r){
    if(l>r){
        return -1;
    }
    int mid = l+(r-l)/2;
    if(arr[mid]=key){
        return mid;
    }
    else if(arr[mid]>key){
        return binarySearch(arr,key, mid+1,r);
    }
    else{
        return binarySearch(arr,key, l,mid);
    }
}

/// 28. check whether a set of parenthesis is valid or not
bool isValidParenthesis(string s, int l , int r){
    if(l>r){
        return true;
    }
    if(s[l]=='(' && s[r]==')'){
        return isValidParenthesis(s,l+1,r-1);
    }
    else{
        return false;
    }
}

int main()
{
    ///check problem number 1
    /*
    int n;
    cin>>n;
    cout<<"Factorial of "<<n<<" = "<<factorial(n)<<endl;

    */

    ///check problem number 2
    /*
    int x,y;
    cin>>x>>y;
    cout<<x<<"^"<<y<<" = "<<power(x,y)<<endl;
    */

     ///check problem number 3
    /*
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    */

     ///check problem number 4
    /*string s;
    getline(cin,s);
    s = removeSpaceandCase(s);
    isPalindromForString(s,0,s.size()-1)?cout<<"True"<<endl:cout<<"Flase"<<endl;
    */

    ///check problem number 5
    /*
    int x,y;
    cin>>x>>y;
    printAllEvenInARange(x,y);
    */

    /// check problem numbers (6 - 16)
    /*
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Given order : ";printArrayInGivenOrder(arr,n-1); // 6
    cout<<"\nReverse order : ";printArrayInReverseOrder(arr,n-1); // 7
    cout<<"\nSum is = "<<sumOfAllElement(arr,n-1)<<endl; // 8
    cout<<"Product is = "<<productOfAllElement(arr,n-1)<<endl; // 9
    cout<<"Max element of the array is = "<<findMax(arr,n-1)<<endl; // 10
    cout<<"Min element of the array is = "<<findMin(arr,n-1)<<endl; // 11
    cout<<"Average of the array is  = "<<average(arr,n)<<endl;  // 12
    cout<<"Odd elements : ";printOddElements(arr, n-1);   // 13
    cout<<"\nPrime elements : ";printAllPrime(arr, n-1);   // 14

    int cntOdd = 0;
    countOdd(arr,n-1,cntOdd);                           //15
    cout<<"\nNumber of odd elements : "<<cntOdd<<endl;   // 15

    int cntPrime = 0;
    countPrime(arr,n-1,cntPrime);                      //16
    cout<<"Number of Prime : "<<cntPrime<<endl;        //16
    */

    /// check problem number 17 18
    /*
    int arr[r][c];
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>arr[i][j];
        }
    }
    int a= findMaxFrom2D(arr,0,0);
    cout<<"Maximum of the 2d array is "<<a<<endl;
    int cnt = 0;
    findNumberOfPrimeIn2D(arr,0,0,cnt);
    cout<<"Number of Prime in 2D array is : "<<cnt<<endl;
    */  /// 18 is not working

    /// check problem number 19
    /*
    int n;
    cin>>n;
    int sum1  = 0;
    series1( n, sum1,1);   // 1+2+3+4+....
    cout<<"Sum of the above series up to "<<n<<"th term is : "<<sum1<<endl;

    int sum2 = 0;
    series2(n,sum2,1);   //1^2 + 2^2 + 3^2 + ......
    cout<<"Sum of the above series up to "<<n<<"th term is : "<<sum2<<endl;

    int sum3 = 0;
    series3(n,sum3,1,3); // 1*3 + 2*5 + 3*7 + ...
    cout<<"Sum of the above series up to "<<n<<"th term is : "<<sum3<<endl;

    int sum4 = 0;
    series4(n,sum4,1,2,3); // 2*3 + 4*5 + 8*7 + 16*9 + ...
    cout<<"Sum of the above series up to "<<n<<"th term is : "<<sum4<<endl;

    int sum5 = 0;
    series5(n,sum5,1,2,3,4);  //2*3*4 + 4*5*3 + 8*7*2+.....
    cout<<"Sum of the above series up to "<<n<<"th term is : "<<sum5<<endl;
    */

    /// check problem number 20 and 21
    /*
    int x, y;
    cin>>x>>y;
    cout<<"GCD of "<<x<<" and "<<y<<" is = "<<GCD(x,y)<<endl;
    cout<<"LCM of "<<x<<" and "<<y<<" is = "<< (x>y?LCM(x,y):LCM(y,x));
    */
    /// check problem number 22, 23 and 24
    /*
    int n;
    cin>>n;
    cout<<"Total Number of Digit = "<<countNumberOfDigit(n)<<endl;
    cout<<"Sum  of All Digit = "<<calculateSumOfAllDigit(n)<<endl;
    cout<<n<<(isPalindromForNumber(n)?" is a Palindrome":" is Not a Palindrome");
    */

    /// check problem number 25
    /*
    string s;
    cin>>s;
    allSubSet(s,-1, "");
    */

    /// check problem number 27
    /*
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;

    binarySearch(arr, key, 0, n-1)==-1?cout<<"Not found "<<endl:cout<<"Found"<<endl;
    */

    /// check problem number 28
    // ()()() this type of valid parenthesis are not handled (((()))) works for this type
    /*
    string s;
    cin>>s;
    (isValidParenthesis(s,0,s.size()-1)==1)?cout<<"Yes Valid"<<endl:cout<<"Not Valid"<<endl;
    */

    return 0;

}

