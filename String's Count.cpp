// Time complexity - O(1)
// Space complexity- O(1)
#define ll long long
long long int countStr(long long int n){
    
    ll a=1; //each character is a
    ll b=n; //np1 - way to choose 1 character as b rest are a
    ll c=(n*(n-1))/2; //(nP2)/2 …cc dividing by 2 because two c
    ll d=n; //np1 - 1 character is b rest are a
    ll e=n*(n-1); //np2 - bc
    ll f=(n*(n-1)*(n-2))/2; //(np3)/2 - bcc
    
    return (a+b+c+d+e+f);
}