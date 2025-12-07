#include <iostream>
#include <exception>
#include <cstring>
using namespace std;
class fournisseur
{
protected:
    long id;
    char *raison_social;
    char *adresse;
    char *mat_fisc;
    float chiff_aff;
    char *groupe;

public:
    fournisseur()
    {
        id = 0;
        raison_social = nullptr;
        adresse = nullptr;
        mat_fisc = nullptr;
        groupe = nullptr;
        chiff_aff = 0;
    }
    fournisseur(long id, char *raison_social, char *adresse, char *mat_fisc, float chiff_aff, char *groupe)
    {
        if (raison_social)
        {
            this->raison_social = new char[strlen(raison_social) + 1];
            strcpy(this->raison_social, raison_social);
        }

        if (adresse)
        {
            this->adresse = new char[strlen(adresse) + 1];
            strcpy(this->adresse, adresse);
        }
        if (groupe)
        {
            this->groupe = new char[strlen(groupe) + 1];
            strcpy(this->groupe, groupe);
        }
        if (mat_fisc)
        {
            this->mat_fisc = new char[strlen(mat_fisc) + 1];
            strcpy(this->mat_fisc, mat_fisc);
        }
        try
        {
            if (id <= 0 || chiff_aff <= 1000)
            {
                throw "errer de saisir";
            }
            else
            {
                this->id = id;
                this->chiff_aff = chiff_aff;
            }
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
    virtual ~fournisseur()
    {
        delete[] groupe;
        delete[] adresse;
        delete[] raison_social;
        delete[] mat_fisc;
    }
    fournisseur(const fournisseur &f)
    {
        if (f.raison_social)
        {
            this->raison_social = new char[strlen(f.raison_social) + 1];
            strcpy(this->raison_social, raison_social);
        }

        if (f.adresse)
        {
            this->adresse = new char[strlen(f.adresse) + 1];
            strcpy(this->adresse, f.adresse);
        }
        if (f.groupe)
        {
            this->groupe = new char[strlen(f.groupe) + 1];
            strcpy(this->groupe, f.groupe);
        }
        if (f.mat_fisc)
        {
            this->mat_fisc = new char[strlen(f.mat_fisc) + 1];
            strcpy(this->mat_fisc, f.mat_fisc);
        }
        id = f.id;
        chiff_aff = f.chiff_aff;
    }
    long get_id()
    {
        return id;
    }
    float get_chiff()
    {
        return chiff_aff;
    }
    void set_id(long id)
    {
        this->id = id;
    }
    void set_chiff(float chiff)
    {
        chiff_aff = chiff;
    }
    char *get_addresse()
    {
        return adresse;
    }
    void set_add(char *add)
    {
        if (add)
        {
            adresse = new char[strlen(add) + 1];
            strcpy(adresse, add);
        }
    }
    virtual float get_chiff_aff()
    {
        return chiff_aff;
    }
    virtual void view()
    {
        cout << "id : " << id << endl;
        cout << "chiffre d'affaires : " << chiff_aff << endl;
        cout << "adresse : " << adresse << endl;
        cout << "matricule fiscale : " << mat_fisc << endl;
        cout << "raison social : " << raison_social << endl;
        cout << "groupe : " << groupe << endl;
    }
    fournisseur operator+(const fournisseur &f)
    {
        try
        {
            if (!(strcmp(groupe, f.groupe) && strcmp(mat_fisc, f.mat_fisc)))
            {
                fournisseur f1(id * 1000 + f.id, groupe, adresse, mat_fisc, chiff_aff + f.chiff_aff, groupe);
                return f1;
            }
            else
            {
                throw "impossible d'additioner";
            }
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
};
class fournisseur_etranger : public fournisseur
{
private:
    char *pays;
    char *devise;
    char *cour_ech;

public:
    fournisseur_etranger(long id, char *raison_social, char *adresse, char *mat_fisc, float chiff_aff, char *groupe, char *pays, char *device, char *cour_ech) : fournisseur(id, raison_social, adresse, mat_fisc, chiff_aff, groupe)
    {
        if (pays)
        {
            this->pays = new char[strlen(pays) + 1];
            strcpy(this->pays, pays);
        }
        if (devise)
        {
            this->devise = new char[strlen(devise) + 1];
            strcpy(this->devise, devise);
        }
        if (cour_ech)
        {
            this->cour_ech = new char[strlen(cour_ech) + 1];
            strcpy(this->cour_ech, cour_ech);
        }
    }
    ~fournisseur_etranger()
    {
        delete[] pays;
        delete[] devise;
        delete[] cour_ech;
    }
    void view()
    {
        fournisseur::view();
        cout << "pays : " << pays << endl;
        cout << "devise : " << devise << endl;
        cout << "cour_ech : " << cour_ech << endl;
    }
};
int main()
{
    fournisseur f1(1, "raison1", "adresse1", "mat1", 2000, "groupe1");
    fournisseur f2(2, "raison2", "adresse2", "mat2", 3000, "groupe1");
    fournisseur f3 = f1 + f2;
    f3.view();
    fournisseur_etranger fe1(3, "raison3", "adresse3", "mat3", 4000, "groupe2", "pays1", "devise1", "cour1");
    fe1.view();
    cout << "//====================POLYMORPHISME==========================" << endl;
    fournisseur *p = new fournisseur;
    p = &f1;
    p->view();
    //===========================================================
    p = &f2;
    p->view();
    return 0;
}