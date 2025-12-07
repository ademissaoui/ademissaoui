template<typename T>
class Tableau {
private:
    int Dim;
    T* V;
    int N;

public:
    // Constructeur avec paramètre par défaut
    Tableau(int dim = 10) : Dim(dim), N(0) {
        V = new T[Dim];
    }

    // Destructeur
    ~Tableau() {
        delete[] V;
    }

    // Insère un élément
    void insere(const T& element) {
        if (N < Dim) {
            V[N++] = element;
        } else {
            cout << "Tableau plein!" << endl;
        }
    }

    // Retourne l'indice du plus grand élément
    int max() const {
        if (N == 0) return -1;
        int idx = 0;
        for (int i = 1; i < N; i++) {
            if (V[i] > V[idx]) idx = i;
        }
        return idx;
    }

    // Retourne l'indice du plus petit élément
    int min() const {
        if (N == 0) return -1;
        int idx = 0;
        for (int i = 1; i < N; i++) {
            if (V[i] < V[idx]) idx = i;
        }
        return idx;
    }

    // Tri par sélection
    void tri() {
        for (int i = 0; i < N - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < N; j++) {
                if (V[j] < V[minIdx]) minIdx = j;
            }
            if (minIdx != i) {
                T temp = V[i];
                V[i] = V[minIdx];
                V[minIdx] = temp;
            }
        }
    }

    // Affichage
    void view() const {
        for (int i = 0; i < N; i++) {
            cout << "Element " << i << ": ";
            V[i].view();
        }
    }
};