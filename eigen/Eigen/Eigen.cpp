#include <iostream>
#include <Eigen/Dense>
#include <random>

using namespace Eigen;
using namespace std;

int main()
{
    std::cout << "1.SORU " << std::endl;
    //1.soru 1 ile 100 arasinda rastgele tam sayilardan oluþan 5x8 matris tanimlayiniz.
    std::srand((unsigned int)time(0));
    MatrixXd matris1 = MatrixXd(5, 8);
    matris1.setRandom();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            matris1(i, j) = static_cast<int>(100 * abs(matris1(i, j)) + 1);
        }
    }
    std::cout << "Matrix m: " << std::endl << matris1 << std::endl;

    std::cout << "2.SORU : \n" << std::endl;
    // 2.soru Rastgele degerlerle bir 5x4x3 dizi olusturun .

    Matrix<Vector3i, 5, 4> matris7;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 4; k++) {
                matris7(j, k)[i] = rand() % 100 + 1;
                cout << matris7(j, k)[i] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }



    // 3.soru Rastgele degerlerle 10x10’luk bir dizi olusturun ve minimum-maksimum degerleri bulun.
    std::cout << "3.SORU : \n" << std::endl;
    std::srand((unsigned int)time(0));
    MatrixXd matris3 = MatrixXd::Random(10, 10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matris3(i, j) = static_cast<int>(100 * abs(matris3(i, j)) + 1);
        }
    }
    int  maksimum = matris3.maxCoeff();
    int  minimum = matris3.minCoeff();
    std::cout << "Matrix d: " << std::endl << matris3 << std::endl;
    std::cout << "Max value: " << std::endl << maksimum << std::endl;
    std::cout << "Min value: " << std::endl << minimum << std::endl;

    std::cout << "4.SORU : \n" << std::endl;
    //4 soru 5x3 matrisi 3x2 matrisle carpin. Bu matrislerin elemanlarýný karsilikli olarak carpin.
    MatrixXd n = MatrixXd::Random(5, 3);
    MatrixXd s = MatrixXd::Random(3, 2);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            n(i, j) = static_cast<int>(100 * abs(n(i, j)) + 1);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            s(i, j) = static_cast<int>(100 * abs(s(i, j)) + 1);
        }
    }

    std::cout << "Matrix carpim : " << std::endl << n * s << std::endl;

    std::cout << "5.SORU : \n" << std::endl;
    // 5.soru 10 boyutunda rastgele vektor olusturun ve maksimum degeri 0 ile deðistirin
    std::srand((unsigned int)time(0));
    VectorXd vector(10);

    vector = vector.setRandom().cwiseAbs();
    for (int i = 0; i < 10; i++) {
        if (vector(i) == vector.maxCoeff())
        {
            vector(i) = 0;
        }

    }
    std::cout << "Vector :\n" << vector << std::endl;

    std::cout << "6.SORU : \n" << std::endl;

    /* 6.soru 100x150 boyutlu bir matrisinin her bir satirindaki deðerleri satir numarasi olacak sekilde MM deðiskeninde tanimlayiniz.
111111...
22222...
33333...
.....
100100100....*/

    int sayac = 1;
    MatrixXd MM = MatrixXd(100, 150);

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 150; j++) {
            MM(i, j) = sayac;
        }
        sayac++;
    }

    std::cout << "Matrix " << std::endl << MM << std::endl;

    std::cout << "7.SORU : \n" << std::endl;
    // 7.soru MM matrisinin dort parcaya bolundugunu dusunun. Sag alt kose (25x25) ile sol ust koseyi(25x25), sag ust köþe(25x25) ile sol alt kosedeki(25x25) degerlerin yerini deðistirin.

    MatrixXd gecici = MatrixXd(25, 25);

    gecici = MM.topLeftCorner(25, 25);
    MM.topLeftCorner(25, 25) = MM.bottomRightCorner(25, 25);
    MM.bottomRightCorner(25, 25) = gecici;

    gecici = MM.topRightCorner(25, 25);
    MM.topRightCorner(25, 25) = MM.bottomLeftCorner(25, 25);
    MM.bottomLeftCorner(25, 25) = gecici;

    std::cout << "Matris  :\n" << MM << std::endl;

    std::cout << "8.SORU : \n" << std::endl;

    // 8.soru 10x10 bir matris icinde 1'den 100'e kadar rakamlari saklayin. Bu matrisinin transpozunu yine ayni deðisken icerisinde saklayin.

    std::srand((unsigned int)time(0));
    MatrixXd matris4 = MatrixXd::Random(10, 10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matris4(i, j) = static_cast<int>(100 * abs(matris4(i, j)) + 1);
        }
    }
    std::cout << "Matrix " << std::endl << matris4 << std::endl;
    matris4.transposeInPlace();
    std::cout << "Matrix " << std::endl << matris4 << std::endl;

    std::cout << "9.SORU : \n" << std::endl;
    // 9.soru 10x10 rastgele tam sayilardan olusan bir matrisin cift sayili satirlari ile cift sayili sutun elemanlarini yer deðistirin. 

    std::srand((unsigned int)time(0));
    MatrixXd matris5 = MatrixXd::Random(10, 10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matris5(i, j) = static_cast<int>(100 * abs(matris5(i, j)) + 1);
        }
    }

    std::cout << "Matrix " << std::endl << matris5 << std::endl;
    for (int i = 0; i < 10; i += 2) {
        for (int j = 0; j < 10; j++) {
            int x = matris5.col(i)[j];
            matris5.col(i)[j] = matris5.row(i)[j];
            matris5.row(i)[j] = x;
        }
    }

    cout << endl << "Degisen Matrix " << endl << matris5 << endl;


    std::cout << "10.SORU : \n" << std::endl;


    // 10.soru 100x100 rastgele sayilardan olusan bir matris icerisinde sifirdan kucuk degerleri pozitif degerleri ile deðistirin.

    MatrixXd matris6 = MatrixXd(100, 100);
    matris6.setRandom();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            matris6(i, j) = static_cast<int>(100 * (matris6(i, j)) + 1);
        }
    }
    std::cout << "Matrix n: " << std::endl << matris6 << std::endl;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (matris6(i, j) < 0) {
                matris6(i, j) *= -1;
            }
        }
    }
    std::cout << "pozitif matris: " << std::endl << matris6 << std::endl;



    std::cout << "11.SORU : \n" << std::endl;
    // 11.soru  10x10 rastgele tam sayilardan olusan bir matrisin satirlarindaki degerleri siralayarak ayni matriste saklayiniz.

    MatrixXd matris8 = MatrixXd::Random(10, 10) * 100;
    MatrixXi f = matris8.cast<int>().array().abs();
    std::cout << " Matrix " << std::endl << f << std::endl;
    for (int i = 0; i < 10; i++) {
        VectorXi rows = f.row(i);
        std::sort(rows.data(), rows.data() + rows.size());
        f.row(i) = rows;
    }
    std::cout << endl << "SIRALI " << endl << f << endl;


}
