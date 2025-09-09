class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie) {
    int i=0;
    int j=0;
     sort(Student.begin(),Student.end());
     sort(Cookie.begin(),Cookie.end());

     while(i<Student.size() && j<Cookie.size()){
        if(Student[i]<=Cookie[j]){
            i++;
            j++;
        }
        else {
           j++; 
        }
     }
     return i;
    }
};