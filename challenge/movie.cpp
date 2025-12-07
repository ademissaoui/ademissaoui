#include <iostream>
#include<vector>
#include<string>
using namespace std;
class movie{
    private:
        string movie_name;
        string rating;
        int watched;
    public:
        string get_name(){
            return movie_name;
        }
        string get_rating(){return rating;}
        int get_watched(){
            return watched;
        }
        movie(string name, string Rating,int Watched){
            movie_name=name;
            rating=Rating;
            watched=Watched;
        }
        ~movie(){}

};
class movies{
    private:
        vector<movie> Movies;
    public:
        movies(){

        }
        bool add_movie(movie M){
            for (size_t i = 0; i < Movies.size(); i++)
            {
                if (Movies[i].get_name()==M.get_name())
                {
                    cout << "the movie is already exist! " << endl;
                    return false;                }
            }
            
            Movies.push_back(M);
            return true;
        }
        void display() {
            for (size_t i = 0; i < Movies.size(); i++)
            {
                cout << "movie name : " << Movies[i].get_name() << endl;
                cout << "rating : " << Movies[i].get_rating() << endl;
                cout << "watched : " << Movies[i].get_watched() << "  time   " << endl;
                cout << "=====================================================" << endl;
            }
            
        }

};
int main(){
    movie m1 ("inception" , "GP7", 5);
    movie m2 ("inception" , "P+18" , 33);
    movies M;
    M.add_movie(m1);
    M.add_movie(m2);
    M.display();
    
    


    


}