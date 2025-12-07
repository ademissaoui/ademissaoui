#include<iostream>
using namespace std;

class matrice; // forward declaration so vect can declare friend using matrice

class vect{
    private:
        double x;
        double y;
        double z;
    public:
        vect(double abs , double ord, double h){
            x = abs;
            y = ord;
            z = h;
        }
    void afficher(){
        cout << "abscise : "<< x<< endl;
        cout << "ordonne : "<< y<< endl;
        cout << "hauteur : "<< z<< endl;  
    }
    friend vect prod(const matrice &mat,const vect &v);

};
class matrice{
    private:
        double (*mat)[3] = new double[3][3];
    public:
        matrice(){
            for(int i = 0 ; i< 3 ; i++){
                for(int j = 0 ; j<3;j++){
                    cout<< "entrer mat[i][j] : "<< endl;
                    cin >> mat[i][j];

                }
            }
        }
        ~matrice(){
            delete[] mat;
        }
        void afficher(){
            for(int i = 0 ; i< 3 ; i++){
                for(int j = 0 ; j<3;j++){
                    cout  << mat[i][j]<< "   "    ;
                }
                cout << endl;
            }
        }
        double get_mat(int i,int j){
            return mat[i][j];
        }
        friend vect prod(const matrice &mat,const vect &v);


};
// corrected implementation of prod: compute matrix-vector product
// original incorrect line: "double resul_x = v.x*mat[0][0]"
vect prod(const matrice &mat,const vect &v){
    // Accessing private member 'mat' of class matrice is allowed because prod is a friend
    double resul_x = v.x * mat.mat[0][0] + v.y * mat.mat[0][1] + v.z * mat.mat[0][2];
    double resul_y = v.x * mat.mat[1][0] + v.y * mat.mat[1][1] + v.z * mat.mat[1][2];
    double resul_z = v.x * mat.mat[2][0] + v.y * mat.mat[2][1] + v.z * mat.mat[2][2];
    return vect(resul_x, resul_y, resul_z);
}

int main (){   
    vect a (2,3,1);
    a.afficher();
    matrice b;
    b.afficher();
}