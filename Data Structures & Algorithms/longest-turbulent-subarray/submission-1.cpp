class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> diff;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int x= arr[i]-arr[i+1];
            diff.push_back(x);
        }
        int cnt=0;
        int maxi=-1e9;
        for(int i=0;i<diff.size();i++){
            cout<<diff[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<diff.size();i++){
            if(i%2){
                if(diff[i]>0){
                    cnt++;
                }
                else{
                    maxi=max(maxi,cnt);
                    cnt=0;
                }
            }
            else{
                if(diff[i]<0){
                    cnt++;
                }
                else{
                    maxi=max(maxi,cnt);
                    cnt=0;
                }
            }
        }
        maxi=max(maxi,cnt);
        cnt=0;
        for(int i=0;i<diff.size();i++){
            if(i%2==0){
                if(diff[i]>0){
                    cnt++;
                }
                else{
                    maxi=max(maxi,cnt);
                    cnt=0;
                }
            }
            else{
                if(diff[i]<0){
                    cnt++;
                }
                else{
                    maxi=max(maxi,cnt);
                    cnt=0;
                }
            }
        }
        maxi=max(maxi,cnt);
        return maxi+1;
    }
};