#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

const int CONSOLE_WIDTH = 80; // Width used for centering the display

// Utility function to print a given number of spaces for centering output
void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        cout << " ";
    }
}

// Abstract base class for all 2D shapes
class Forme {
public:
    virtual double area() const = 0;       // Pure virtual function for area calculation
    virtual double perimetre() const = 0;    // Pure virtual function for perimeter calculation
    virtual void afficher() const = 0;       // Pure virtual function for displaying the ASCII representation
    virtual ~Forme() {}                     // Virtual destructor
};

// Abstract base class for all 3D shapes
class Forme3D {
public:
    virtual double volume() const = 0;      // Pure virtual function for volume calculation
    virtual double totalArea() const = 0;   // Pure virtual function for surface area calculation
    virtual void afficher() const = 0;      // Pure virtual function for displaying the shape
    virtual ~Forme3D() {}                   // Virtual destructor
};

// Function to display the menu and get the user's choice
int getResponse() {
    int userChoice = 0;
    cout << "1. Rectangle" << endl;
    cout << "2. Triangle" << endl;
    cout << "3. Carré (Square)" << endl;
    cout << "4. Cercle (Circle)" << endl;
    cout << "5. Losange (Diamond)" << endl;
    cout << "6. Parallélogramme (Parallelogram)" << endl;
    cout << "7. Trapèze (Trapezoid)" << endl;
    cout << "8. Polygone (Polygon)" << endl;
    cout << "9. Cube" << endl;
    cout << "10. Rectangle3D (Rectangular Parallelepiped)" << endl;
    cout << "11. Cylinder" << endl;
    cout << "12. Sphere" << endl;
    cout << "13. Dodecahedron" << endl;
    cout << "14. Icosahedron" << endl;
    cout << "15. Cone" << endl;
    cout << "16. Regular Pyramid" << endl;
    cout << "Quelle est ton choix ? " << endl;
    cin >> userChoice;
    return userChoice;
}

// ---------------------- Rectangle Class ----------------------
class Rectangle : public Forme {
private:
    double largeur;
    double hauteur;
public:
    Rectangle(double l, double h) : largeur(l), hauteur(h) {}

    double area() const override {
        return largeur * hauteur;
    }

    double perimetre() const override {
        return 2 * (largeur + hauteur);
    }

    void afficher() const override {
        int w = static_cast<int>(largeur);
        int h = static_cast<int>(hauteur);
        int offset = (CONSOLE_WIDTH - w) / 2;
        cout << "\n--- Rectangle ---" << endl;
        for (int i = 0; i < h; i++) {
            printSpaces(offset);
            for (int j = 0; j < w; j++) {
                // Draw the border using '#' character
                if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
                    cout << "#";
                else
                    cout << " ";
            }
            cout << endl;
        }
        cout << "\nLegend: '#' represents the rectangle's border." << endl;
        cout << "Aire = " << area() << "   Périmètre = " << perimetre() << endl;
    }
};

// ---------------------- Triangle Class ----------------------
class Triangle : public Forme {
private:
    double base;
    double hauteur;
public:
    Triangle(double b, double h) : base(b), hauteur(h) {}

    double area() const override {
        return (base * hauteur) / 2;
    }

    double perimetre() const override {
        double hypotenuse = sqrt(base * base + hauteur * hauteur);
        return base + hauteur + hypotenuse;
    }

    void afficher() const override {
        int b = static_cast<int>(base);
        int h = static_cast<int>(hauteur);
        cout << "\n--- Triangle (Right Triangle) ---" << endl;
        for (int i = 1; i <= h; i++) {
            int stars = (i * b) / h;
            if (stars < 1) stars = 1;
            int offset = (CONSOLE_WIDTH - stars) / 2;
            printSpaces(offset);
            for (int j = 0; j < stars; j++) {
                cout << "#";
            }
            cout << endl;
        }
        cout << "\nLegend: '#' represents the lines of the triangle." << endl;
        cout << "Aire = " << area() << "   Périmètre = " << perimetre() << endl;
    }
};

// ---------------------- Square Class ----------------------
class Square : public Forme {
private:
    double cote;
public:
    Square(double c) : cote(c) {}

    double area() const override {
        return cote * cote;
    }

    double perimetre() const override {
        return 4 * cote;
    }

    void afficher() const override {
        int side = static_cast<int>(cote);
        int offset = (CONSOLE_WIDTH - side) / 2;
        cout << "\n--- Carré ---" << endl;
        for (int i = 0; i < side; i++) {
            printSpaces(offset);
            for (int j = 0; j < side; j++) {
                if (i == 0 || i == side - 1 || j == 0 || j == side - 1)
                    cout << "#";
                else
                    cout << " ";
            }
            cout << endl;
        }
        cout << "\nLegend: '#' represents the square's border." << endl;
        cout << "Aire = " << area() << "   Périmètre = " << perimetre() << endl;
    }
};

// ---------------------- Circle Class ----------------------
class Circle : public Forme {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimetre() const override {
        return 2 * M_PI * radius;
    }

    void afficher() const override {
        int r = static_cast<int>(radius);
        cout << "\n--- Cercle ---" << endl;
        // Loop through a square grid centered on (0,0)
        for (int y = -r; y <= r; y++) {
            string line = "";
            for (int x = -r; x <= r; x++) {
                // Fill the inside of the circle with '#'
                if (x * x + y * y <= r * r)
                    line += "#";
                else
                    line += " ";
            }
            int offset = (CONSOLE_WIDTH - line.size()) / 2;
            printSpaces(offset);
            cout << line << endl;
        }
        cout << "\nLegend: '#' represents the inside of the circle." << endl;
        cout << "Aire = " << area() << "   Périmètre = " << perimetre() << endl;
    }
};

// ---------------------- Diamond Class ----------------------
class Diamond : public Forme {
private:
    double largeur; // first diagonal
    double hauteur; // second diagonal
public:
    Diamond(double l, double h) : largeur(l), hauteur(h) {}

    double area() const override {
        return (largeur * hauteur) / 2;
    }

    double perimetre() const override {
        double side = sqrt((largeur * largeur + hauteur * hauteur) / 4);
        return 4 * side;
    }

    void afficher() const override {
        int d1 = static_cast<int>(largeur);
        int d2 = static_cast<int>(hauteur);
        int half1 = d1 / 2;
        int half2 = d2 / 2;
        cout << "\n--- Losange (Diamond) ---" << endl;
        for (int y = -half2; y <= half2; y++) {
            int width = static_cast<int>((1.0 - fabs(double(y)) / half2) * half1);
            int lineWidth = 2 * width + 1;
            int offset = (CONSOLE_WIDTH - lineWidth) / 2;
            printSpaces(offset);
            for (int x = -width; x <= width; x++) {
                cout << "#";
            }
            cout << endl;
        }
        cout << "\nLegend: '#' represents the diamond's border." << endl;
        cout << "Aire = " << area() << "   Périmètre = " << perimetre() << endl;
    }
};

// ---------------------- Parallelogram Class ----------------------
class Parallelogram : public Forme {
private:
    double largeur;
    double hauteur;
public:
    Parallelogram(double l, double h) : largeur(l), hauteur(h) {}

    double area() const override {
        return largeur * hauteur;
    }

    double perimetre() const override {
        return 2 * (largeur + hauteur);
    }

    void afficher() const override {
        int w = static_cast<int>(largeur);
        int h = static_cast<int>(hauteur);
        cout << "\n--- Parallélogramme (Parallelogram) ---" << endl;
        for (int i = 0; i < h; i++) {
            // Offset to simulate inclination
            int offset = (CONSOLE_WIDTH - w - h) / 2 + i;
            printSpaces(offset);
            for (int j = 0; j < w; j++) {
                cout << "#";
            }
            cout << endl;
        }
        cout << "\nLegend: '#' represents the parallelogram's border." << endl;
        cout << "Aire = " << area() << "   Périmètre = " << perimetre() << endl;
    }
};

// ---------------------- Trapeze Class ----------------------
class Trapeze : public Forme {
private:
    double smLargeur; // small base
    double bgLargeur; // large base
    double hauteur;
public:
    Trapeze(double sL, double bL, double h) : smLargeur(sL), bgLargeur(bL), hauteur(h) {}

    double area() const override {
        return ((smLargeur + bgLargeur) / 2) * hauteur;
    }

    double perimetre() const override {
        double diff = (bgLargeur - smLargeur) / 2;
        double leg = sqrt(hauteur * hauteur + diff * diff);
        return smLargeur + bgLargeur + 2 * leg;
    }

    void afficher() const override {
        int small = static_cast<int>(smLargeur);
        int big = static_cast<int>(bgLargeur);
        int h = static_cast<int>(hauteur);
        cout << "\n--- Trapèze (Trapezoid) ---" << endl;
        for (int i = 0; i < h; i++) {
            // To avoid division by zero if h == 1
            int currentWidth = (h > 1) ? (small + ((big - small) * i) / (h - 1)) : small;
            int offset = (CONSOLE_WIDTH - currentWidth) / 2;
            printSpaces(offset);
            for (int j = 0; j < currentWidth; j++) {
                cout << "#";
            }
            cout << endl;
        }
        cout << "\nLegend: '#' represents the trapezoid's border." << endl;
        cout << "Aire = " << area() << "   Périmètre = " << perimetre() << endl;
    }
};

// ---------------------- Regular Polygon Class ----------------------
class Polygone : public Forme {
private:
    double cote;    // Length of one side
    double radius;  // Radius of the circumscribed circle
    int nombre;     // Number of sides
public:
    Polygone(double c, double r, int n) : cote(c), radius(r), nombre(n) {}
    
    double area() const override {
        return 0.5 * nombre * radius * radius * sin((2 * M_PI) / nombre);
    }
    
    double perimetre() const override {
        return nombre * cote;
    }
    
    void afficher() const override {
        cout << "\n--- Regular Polygon ---" << endl;
        cout << "Number of sides: " << nombre << endl;
        cout << "Length of one side: " << cote << endl;
        cout << "Circumscribed circle radius: " << radius << endl;
        cout << "Aire = " << area() << "   Périmètre = " << perimetre() << endl;
        cout << "\nLegend: ASCII representation is not available for this polygon." << endl;
    }
};

// ---------------------- Cube Class (3D Shape) ----------------------
class Cube : public Forme3D {
private:
    double cote;
public:
    Cube(double c) : cote(c) {}

    double volume() const override {
        return cote * cote * cote;
    }

    double totalArea() const override {
        return 6 * cote * cote;
    }

    void afficher() const override {
        cout << "\n--- Cube ---" << endl;
        cout << "Côté: " << cote << endl;
        cout << "Volume = " << volume() << " cm³" << endl;
        cout << "Surface totale = " << totalArea() << " cm²" << endl;
    }
};

// ---------------------- Rectangular Parallelepiped Class (3D Shape) ----------------------
class Rectangle3D : public Forme3D {
private:
    double hauteur;
    double smLargeur;
    double bgLargeur;
public:
    Rectangle3D(double h, double smL, double bgL) : hauteur(h), smLargeur(smL), bgLargeur(bgL) {}
    
    double volume() const override {
        return hauteur * smLargeur * bgLargeur;
    }

    double totalArea() const override {
        return 2 * (bgLargeur * smLargeur + bgLargeur * hauteur + smLargeur * hauteur);
    }

    void afficher() const override {
        cout << "\n--- Rectangle3D (Rectangular Parallelepiped) ---" << endl;
        cout << "Volume = " << volume() << " cm³" << endl;
        cout << "Surface totale = " << totalArea() << " cm²" << endl;
    }
};

// ---------------------- Cylinder Class (3D Shape) ----------------------
class Cylinder : public Forme3D {
    private:
        double radius;
        double hauteur;
    public:
        Cylinder(double r, double h) : radius(r), hauteur(h) {}

        double volume() const override {
            return (M_PI * radius * radius) * hauteur;
        }

        double totalArea() const override {
            return 2 * M_PI * radius * radius + 2 * M_PI * radius * hauteur;
        }

        void afficher() const override {
            cout << "\n--- Cylindre ---" << endl;
            cout << "Volume = " << volume() << " cm³" << endl;
            cout << "Surface totale = " << totalArea() << " cm²" << endl;
        }     
};

// ---------------------- Sphere Class (3D Shape) ----------------------
class Sphere : public Forme3D {
    private:
        double radius;
    public:
        Sphere(double r) : radius(r) {}

        double volume() const override {
            return (4.0/3.0) * M_PI * radius * radius * radius;
        }

        double totalArea() const override {
            return 4 * M_PI * radius * radius;
        }

        void afficher() const override {
            cout << "\n--- Sphere ---" << endl;
            cout << "Volume = " << volume() << " cm³" << endl;
            cout << "Surface totale = " << totalArea() << " cm²" << endl;
        }     
};

// ---------------------- Dodecahedron Class (3D Shape) ----------------------
class Dodecahedron : public Forme3D {
    private:
        double edge;
    public:
        Dodecahedron(double e) : edge(e) {}

        double volume() const override {
            return (1.0 / 4.0) * (15 + 7 * sqrt(5)) * pow(edge, 3);
        }

        double totalArea() const override {
            return 3 * sqrt(25 + 10 * sqrt(5)) * edge * edge;
        }

        void afficher() const override {
            cout << "\n--- Dodecahedron ---" << endl;
            cout << "Volume = " << volume() << " cm³" << endl;
            cout << "Surface totale = " << totalArea() << " cm²" << endl;
        }     
};

// ---------------------- Icosahedron Class (3D Shape) ----------------------
class Icosahedron : public Forme3D {
    private:
        double edge;
    public:
        Icosahedron(double e) : edge(e) {}

        double totalArea() const override {
            return 5 * sqrt(3) * edge * edge;
        }

        double volume() const override {
            return (5.0 / 12.0) * (3 + sqrt(5)) * pow(edge, 3);
        }

        void afficher() const override {
            cout << "\n--- Icosahedron ---" << endl;
            cout << "Volume = " << volume() << " cm³" << endl;
            cout << "Surface totale = " << totalArea() << " cm²" << endl;
        }     
};

// ---------------------- Cone Class (3D Shape) ----------------------
class Cone : public Forme3D {
    private:
        double radius;
        double hauteur;
    public:
        Cone(double r, double h) : radius(r), hauteur(h) {}

        double volume() const override {
            return (1.0 / 3.0) * M_PI * radius * radius * hauteur;
        }

        double totalArea() const override {
            return M_PI * radius * (radius + slantHeight());
        }
        
        // Utility function to calculate the slant height of the cone
        double slantHeight() const {
            return sqrt(hauteur * hauteur + radius * radius);
        }

        void afficher() const override {
            cout << "\n--- Cone ---" << endl;
            cout << "Volume = " << volume() << " cm³" << endl;
            cout << "Surface totale = " << totalArea() << " cm²" << endl;
        }     
};

// ---------------------- Regular Pyramid (3D Shape) ----------------------
class Pyramid : public Forme3D {
    private:
        double baseSide;
        double hauteur;
    public:
        Pyramid(double b, double h) : baseSide(b), hauteur(h) {}

        double volume() const override {
            return (1.0 / 3.0) * (baseSide * baseSide) * hauteur;
        }

        double totalArea() const override {
            double baseArea = baseSide * baseSide;
            double lateralArea = 2 * baseSide * slantHeight();
            return baseArea + lateralArea;
        }
        
        // Utility function to calculate the slant height of the pyramid
        double slantHeight() const {
            return sqrt((baseSide / 2) * (baseSide / 2) + hauteur * hauteur);
        }

        void afficher() const override {
            cout << "\n--- Pyramid ---" << endl;
            cout << "Volume = " << volume() << " cm³" << endl;
            cout << "Surface totale = " << totalArea() << " cm²" << endl;
        }     
};

// ---------------------- Main Function ----------------------
int main() {
    int choix = getResponse();
    Forme* forme = nullptr;
    Forme3D* forme3D = nullptr;

    switch (choix) {
        case 1: {
            double largeur, hauteur;
            cout << "Entrez la largeur du rectangle :" << endl;
            cin >> largeur;
            cout << "Entrez la hauteur du rectangle :" << endl;
            cin >> hauteur;
            forme = new Rectangle(largeur, hauteur);
            break;
        }
        case 2: {
            double base, hauteur;
            cout << "Entrez la base du triangle :" << endl;
            cin >> base;
            cout << "Entrez la hauteur du triangle :" << endl;
            cin >> hauteur;
            forme = new Triangle(base, hauteur);
            break;
        }
        case 3: {
            double cote;
            cout << "Entrez la longueur du côté du carré : " << endl;
            cin >> cote;
            forme = new Square(cote);
            break;
        }
        case 4: {
            double radius;
            cout << "Entrez le rayon du cercle : " << endl;
            cin >> radius;
            forme = new Circle(radius);
            break;
        }
        case 5: {
            double largeur, hauteur;
            cout << "Entrez la première diagonale (largeur) du losange : " << endl;
            cin >> largeur;
            cout << "Entrez la deuxième diagonale (hauteur) du losange : " << endl;
            cin >> hauteur;
            forme = new Diamond(largeur, hauteur);
            break;
        }
        case 6: {
            double largeur, hauteur;
            cout << "Entrez la largeur du parallélogramme : " << endl;
            cin >> largeur;
            cout << "Entrez la hauteur du parallélogramme : " << endl;
            cin >> hauteur;
            forme = new Parallelogram(largeur, hauteur);
            break;
        }
        case 7: {
            double smLargeur, bgLargeur, hauteur;
            cout << "Entrez la petite base du trapèze : " << endl;
            cin >> smLargeur;
            cout << "Entrez la grande base du trapèze : " << endl;
            cin >> bgLargeur;
            cout << "Entrez la hauteur du trapèze : " << endl;
            cin >> hauteur;
            forme = new Trapeze(smLargeur, bgLargeur, hauteur);
            break;
        }
        case 8: {
            double cote, radius;
            int nombre;
            cout << "Entrez la longueur d'un côté du polygone : " << endl;
            cin >> cote;
            cout << "Entrez le rayon du cercle circonscrit : " << endl;
            cin >> radius;
            cout << "Entrez le nombre de côtés du polygone : " << endl;
            cin >> nombre;
            forme = new Polygone(cote, radius, nombre);
            break;
        }
        case 9: {
            double cote;
            cout << "Entrez la longueur du côté du cube : " << endl;
            cin >> cote;
            forme3D = new Cube(cote);
            break;
        }
        case 10: {
            double hauteur, smLargeur, bgLargeur;
            cout << "Entrez la hauteur de votre forme rectangle : " << endl;
            cin >> hauteur;
            cout << "Entrez la grande longeur de votre forme : " << endl;
            cin >> bgLargeur;
            cout << "Entrez la petite longeur de votre forme : " << endl;
            cin >> smLargeur;
            forme3D = new Rectangle3D(hauteur, smLargeur, bgLargeur);
            break;
        }
        case 11: {
            double radius, hauteur;
            cout << "Entrez la hauteur de votre cylindre : " << endl;
            cin >> hauteur;
            cout << "Entrez le rayon de votre cylindre : " << endl;
            cin >> radius;
            forme3D = new Cylinder(radius, hauteur);
            break;
        }
        case 12: {
            double radius;
            cout << "Entrez le rayon de votre sphère : " << endl;
            cin >> radius;
            forme3D = new Sphere(radius);
            break;
        }
        case 13: {
            double edge;
            cout << "Entrez la longueur de l’arête : " << endl;
            cin >> edge;
            forme3D = new Dodecahedron(edge);
            break;
        }
        case 14: {
            double edge;
            cout << "Entrez la longueur de l’arête : " << endl;
            cin >> edge;
            forme3D = new Icosahedron(edge);
            break;
        }
        case 15: {
            double radius, hauteur;
            cout << "Entrez la hauteur de votre cône : " << endl;
            cin >> hauteur;
            cout << "Entrez le rayon de votre cône : " << endl;
            cin >> radius;
            forme3D = new Cone(radius, hauteur);
            break;
        }
        case 16: {
            double baseSide, hauteur;
            cout << "Entrez la hauteur de votre pyramide : " << endl;
            cin >> hauteur;
            cout << "Entrez la mesure de la base de votre pyramide : " << endl;
            cin >> baseSide;
            forme3D = new Pyramid(baseSide, hauteur);
            break;
        }
        default:
            cout << "Choix invalide" << endl;
            return 1;
    }

    if (forme) {
        forme->afficher();
        delete forme; // Free memory
    } else if (forme3D) {
        forme3D->afficher();
        delete forme3D; // Free memory
    } else {
        cout << "No shape selected." << endl;
    }

    return 0;
}
