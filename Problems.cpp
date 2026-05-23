#include <iostream>
#include "Problems.h"
#include "Helpers.h"
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <ctime>
#include <chrono>

using namespace std;

void Problem1() {
    cout << "Find the sum of all the multiples of 3 or 5 below 1000." << endl;
    
    int sum = 0;

    for(int i = 3; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            cout << "Found one: " << i << endl;
            sum += i;
        }
    }

    cout << "Sum: " << sum << endl;
}

void Problem2() {
    cout << "By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms." << endl;
    
    int sum = 0;
    
    int h = 1;
    int i = 2;
    while(i <= 4000000) {
        if (i % 2 == 0) {
            sum += i;
        }
        int tmp = i + h;
        h = i;
        i = tmp;
    }

    cout << "Sum: " << sum << endl;
}

void Problem3() {
    cout << "What is the largest prime factor of the number 600851475143?" << endl;
    
    long long num = 600851475143;

    long maxFactor;
    
    for(maxFactor = floor(pow(num, 0.5)); maxFactor > 1; maxFactor--) {
        if (num % maxFactor == 0) {
            if (IsPrime(maxFactor)) break;
        }
    }

    cout << "Largest prime factor: " << maxFactor << endl;
}

void Problem4() {
    cout << "Find the largest palindrome made from the product of two 3-digit numbers." << endl;
    
    int largest = 0;
    for(int num1 = 999; num1 >= 100; num1--) {
        for(int num2 = num1; num2 >= 100; num2--) {
            int product = num1 * num2;
            if (largest >= product && num2 == num1) {
                num1 = 0;
                num2 = 0;
                break;
            }
            if (IsPalindrome(product) && product > largest) {
                largest = product;
                break;
            }
        }
    }

    cout << "Largest palindrome: " << largest << endl;
}

void Problem5() {
    cout << "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?" << endl;
    
    int maxDivisor = 20;
    bool finding = true;
    long long smallestNum = maxDivisor * (maxDivisor - 1);
    while(finding && smallestNum < 500000000) {
        for(int i = 2; i < maxDivisor; i++) {
            if(smallestNum % i != 0) break;
            if (i == maxDivisor - 1) finding = false;
        }
        if(finding) smallestNum += maxDivisor;
    }
    
    cout << "Smallest number: " << smallestNum << endl;
}

void Problem6() {
    cout << "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum." << endl;
    
    int maxNum = 100;
    long long sumOfSq = 0;
    int sum = 0;
    for(int i = 1; i <= maxNum; i++) {
        sum += i;
        sumOfSq += (i * i);
    }

    long long sqOfSum = (sum * sum);
    long long difference = sqOfSum - sumOfSq;
    
    cout << "Difference: " << difference << endl;
}

void Problem7() {
    cout << "What is the 10,001st prime number?" << endl;
    
    int primeToFind = 10001;
    int primesFound = 0;
    int i = 1;
    while (primesFound < primeToFind) {
        i++;
        if(IsPrime(i)) primesFound++;
    }
    
    cout << "10,001st prime: " << i << endl;
}

void Problem8() {
    cout << "Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?" << endl;
    
    string numStr = "";
    numStr += "73167176531330624919225119674426574742355349194934";
    numStr += "96983520312774506326239578318016984801869478851843";
    numStr += "85861560789112949495459501737958331952853208805511";
    numStr += "12540698747158523863050715693290963295227443043557";
    numStr += "66896648950445244523161731856403098711121722383113";
    numStr += "62229893423380308135336276614282806444486645238749";
    numStr += "30358907296290491560440772390713810515859307960866";
    numStr += "70172427121883998797908792274921901699720888093776";
    numStr += "65727333001053367881220235421809751254540594752243";
    numStr += "52584907711670556013604839586446706324415722155397";
    numStr += "53697817977846174064955149290862569321978468622482";
    numStr += "83972241375657056057490261407972968652414535100474";
    numStr += "82166370484403199890008895243450658541227588666881";
    numStr += "16427171479924442928230863465674813919123162824586";
    numStr += "17866458359124566529476545682848912883142607690042";
    numStr += "24219022671055626321111109370544217506941658960408";
    numStr += "07198403850962455444362981230987879927244284909188";
    numStr += "84580156166097919133875499200524063689912560717606";
    numStr += "05886116467109405077541002256983155200055935729725";
    numStr += "71636269561882670428252483600823257530420752963450";

    long long maxProduct = 0;
    int numIndexes = 13;
    for(int i = 0; i < numStr.length() - (numIndexes - 1); i++){
        long long product = stoi(numStr.substr(i, 1)); 
        for(int j = i + 1; j < i + numIndexes; j++) {
            product *= stoi(numStr.substr(j, 1));
        }
        if (product > maxProduct) maxProduct = product;
    }
    
    
    cout << "Max product: " << maxProduct << endl;
}

void Problem9() {
    cout << "There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc." << endl;
    
    int pySum = 1000;
    long pyProduct = 0;

    for(int a = 1; a < pySum; a++) {
        int aa = a * a;
        for(int b = a + 1; b < pySum; b++) {
            int bb = b * b;
            if (a + b >= pySum) break;
            for(int c = b + 1; c < pySum; c++) {
                int sum = a + b + c;
                if (sum > pySum) break;
                if (sum == pySum) {
                    if(aa + bb == c * c) {
                        pyProduct = a * b * c;
                        break;
                    }
                }
            }
            if(pyProduct != 0) break;
        }
        if(pyProduct != 0) break;
    }
    
    cout << "Product: " << pyProduct << endl;
}

void Problem10() {
    cout << "Find the sum of all the primes below two million." << endl;
    
    int max = 2000000;
    long long sum = 0;
    
    for(int i = 2; i < max; i++) {
        if(IsPrime(i)) sum += i;
    }
    
    cout << "Sum: " << sum << endl;
}

void Problem11() {
    cout << "What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20x20 grid?" << endl;
    
    long maxProduct = 0;
    int numOfNums = 4;
    vector<vector<int>> grid;
    grid.reserve(20);
    grid.push_back({8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8});
    grid.push_back({49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0});
    grid.push_back({81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65});
    grid.push_back({52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91});
    grid.push_back({22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80});
    grid.push_back({24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50});
    grid.push_back({32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70});
    grid.push_back({67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21});
    grid.push_back({24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72});
    grid.push_back({21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95});
    grid.push_back({78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92});
    grid.push_back({16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57});
    grid.push_back({86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58});
    grid.push_back({19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40});
    grid.push_back({4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66});
    grid.push_back({88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69});
    grid.push_back({4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36});
    grid.push_back({20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16});
    grid.push_back({20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54});
    grid.push_back({1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48});

    for(int y = 0; y < grid.capacity(); y++) {
        vector<int>& rowRef = grid.at(y);
        bool canNorth = (y >= numOfNums);
        bool canSouth = (y + (numOfNums - 1) < grid.capacity());
        for(int x = 0; x < rowRef.capacity(); x++) {
            bool canEast = (x + (numOfNums - 1) < rowRef.capacity());
            long nProd = rowRef.at(x);
            long neProd = nProd;
            long eProd = nProd;
            long seProd = nProd;
            for(int mod = 1; mod < numOfNums; mod++) {
                //Check N Adjacent
                if(canNorth) nProd *= grid.at(y - mod).at(x);
                //Check NE Adjacent
                if(canNorth && canEast) neProd *= grid.at(y - mod).at(x + mod);
                //Check E Adjacent
                if(canEast) eProd *= grid.at(y).at(x + mod);
                //Check SE Adjacent
                if(canSouth && canEast) seProd *= grid.at(y + mod).at(x + mod);

            }
            if (nProd > maxProduct) maxProduct = nProd;
            if (neProd > maxProduct) maxProduct = neProd;
            if (eProd > maxProduct) maxProduct = eProd;
            if (seProd > maxProduct) maxProduct = seProd;
        }
    }
    
    cout << "Max product: " << maxProduct << endl;
}

void Problem12() {
    cout << "What is the value of the first triangle number to have over five hundred divisors?" << endl;
    
    int triNum = 0;
    int i = 1;
    int maxDivisors = 500;
    bool searching = true;
    
    while(searching) {
        triNum += i;
        int numDivisors = GetNumOfDivisors(triNum);
        if(numDivisors > maxDivisors) {
            searching = false;
            break;
        }
        i++;
    }
    
    cout << "Triangle number: " << triNum << endl;
}

void Problem13() {
    cout << "Work out the first ten digits of the sum of the following one-hundred 50-digit numbers." << endl;
    
    UnsignedSuperUltraLong TestVal = UnsignedSuperUltraLong("37107287533902102798797998220837590246510135740250", 50);
    TestVal+=UnsignedSuperUltraLong("46376937677490009712648124896970078050417018260538", 50);
    TestVal+=UnsignedSuperUltraLong("74324986199524741059474233309513058123726617309629", 50);
    TestVal+=UnsignedSuperUltraLong("91942213363574161572522430563301811072406154908250", 50);
    TestVal+=UnsignedSuperUltraLong("23067588207539346171171980310421047513778063246676", 50);
    TestVal+=UnsignedSuperUltraLong("89261670696623633820136378418383684178734361726757", 50);
    TestVal+=UnsignedSuperUltraLong("28112879812849979408065481931592621691275889832738", 50);
    TestVal+=UnsignedSuperUltraLong("44274228917432520321923589422876796487670272189318", 50);
    TestVal+=UnsignedSuperUltraLong("47451445736001306439091167216856844588711603153276", 50);
    TestVal+=UnsignedSuperUltraLong("70386486105843025439939619828917593665686757934951", 50);
    TestVal+=UnsignedSuperUltraLong("62176457141856560629502157223196586755079324193331", 50);
    TestVal+=UnsignedSuperUltraLong("64906352462741904929101432445813822663347944758178", 50);
    TestVal+=UnsignedSuperUltraLong("92575867718337217661963751590579239728245598838407", 50);
    TestVal+=UnsignedSuperUltraLong("58203565325359399008402633568948830189458628227828", 50);
    TestVal+=UnsignedSuperUltraLong("80181199384826282014278194139940567587151170094390", 50);
    TestVal+=UnsignedSuperUltraLong("35398664372827112653829987240784473053190104293586", 50);
    TestVal+=UnsignedSuperUltraLong("86515506006295864861532075273371959191420517255829", 50);
    TestVal+=UnsignedSuperUltraLong("71693888707715466499115593487603532921714970056938", 50);
    TestVal+=UnsignedSuperUltraLong("54370070576826684624621495650076471787294438377604", 50);
    TestVal+=UnsignedSuperUltraLong("53282654108756828443191190634694037855217779295145", 50);
    TestVal+=UnsignedSuperUltraLong("36123272525000296071075082563815656710885258350721", 50);
    TestVal+=UnsignedSuperUltraLong("45876576172410976447339110607218265236877223636045", 50);
    TestVal+=UnsignedSuperUltraLong("17423706905851860660448207621209813287860733969412", 50);
    TestVal+=UnsignedSuperUltraLong("81142660418086830619328460811191061556940512689692", 50);
    TestVal+=UnsignedSuperUltraLong("51934325451728388641918047049293215058642563049483", 50);
    TestVal+=UnsignedSuperUltraLong("62467221648435076201727918039944693004732956340691", 50);
    TestVal+=UnsignedSuperUltraLong("15732444386908125794514089057706229429197107928209", 50);
    TestVal+=UnsignedSuperUltraLong("55037687525678773091862540744969844508330393682126", 50);
    TestVal+=UnsignedSuperUltraLong("18336384825330154686196124348767681297534375946515", 50);
    TestVal+=UnsignedSuperUltraLong("80386287592878490201521685554828717201219257766954", 50);
    TestVal+=UnsignedSuperUltraLong("78182833757993103614740356856449095527097864797581", 50);
    TestVal+=UnsignedSuperUltraLong("16726320100436897842553539920931837441497806860984", 50);
    TestVal+=UnsignedSuperUltraLong("48403098129077791799088218795327364475675590848030", 50);
    TestVal+=UnsignedSuperUltraLong("87086987551392711854517078544161852424320693150332", 50);
    TestVal+=UnsignedSuperUltraLong("59959406895756536782107074926966537676326235447210", 50);
    TestVal+=UnsignedSuperUltraLong("69793950679652694742597709739166693763042633987085", 50);
    TestVal+=UnsignedSuperUltraLong("41052684708299085211399427365734116182760315001271", 50);
    TestVal+=UnsignedSuperUltraLong("65378607361501080857009149939512557028198746004375", 50);
    TestVal+=UnsignedSuperUltraLong("35829035317434717326932123578154982629742552737307", 50);
    TestVal+=UnsignedSuperUltraLong("94953759765105305946966067683156574377167401875275", 50);
    TestVal+=UnsignedSuperUltraLong("88902802571733229619176668713819931811048770190271", 50);
    TestVal+=UnsignedSuperUltraLong("25267680276078003013678680992525463401061632866526", 50);
    TestVal+=UnsignedSuperUltraLong("36270218540497705585629946580636237993140746255962", 50);
    TestVal+=UnsignedSuperUltraLong("24074486908231174977792365466257246923322810917141", 50);
    TestVal+=UnsignedSuperUltraLong("91430288197103288597806669760892938638285025333403", 50);
    TestVal+=UnsignedSuperUltraLong("34413065578016127815921815005561868836468420090470", 50);
    TestVal+=UnsignedSuperUltraLong("23053081172816430487623791969842487255036638784583", 50);
    TestVal+=UnsignedSuperUltraLong("11487696932154902810424020138335124462181441773470", 50);
    TestVal+=UnsignedSuperUltraLong("63783299490636259666498587618221225225512486764533", 50);
    TestVal+=UnsignedSuperUltraLong("67720186971698544312419572409913959008952310058822", 50);
    TestVal+=UnsignedSuperUltraLong("95548255300263520781532296796249481641953868218774", 50);
    TestVal+=UnsignedSuperUltraLong("76085327132285723110424803456124867697064507995236", 50);
    TestVal+=UnsignedSuperUltraLong("37774242535411291684276865538926205024910326572967", 50);
    TestVal+=UnsignedSuperUltraLong("23701913275725675285653248258265463092207058596522", 50);
    TestVal+=UnsignedSuperUltraLong("29798860272258331913126375147341994889534765745501", 50);
    TestVal+=UnsignedSuperUltraLong("18495701454879288984856827726077713721403798879715", 50);
    TestVal+=UnsignedSuperUltraLong("38298203783031473527721580348144513491373226651381", 50);
    TestVal+=UnsignedSuperUltraLong("34829543829199918180278916522431027392251122869539", 50);
    TestVal+=UnsignedSuperUltraLong("40957953066405232632538044100059654939159879593635", 50);
    TestVal+=UnsignedSuperUltraLong("29746152185502371307642255121183693803580388584903", 50);
    TestVal+=UnsignedSuperUltraLong("41698116222072977186158236678424689157993532961922", 50);
    TestVal+=UnsignedSuperUltraLong("62467957194401269043877107275048102390895523597457", 50);
    TestVal+=UnsignedSuperUltraLong("23189706772547915061505504953922979530901129967519", 50);
    TestVal+=UnsignedSuperUltraLong("86188088225875314529584099251203829009407770775672", 50);
    TestVal+=UnsignedSuperUltraLong("11306739708304724483816533873502340845647058077308", 50);
    TestVal+=UnsignedSuperUltraLong("82959174767140363198008187129011875491310547126581", 50);
    TestVal+=UnsignedSuperUltraLong("97623331044818386269515456334926366572897563400500", 50);
    TestVal+=UnsignedSuperUltraLong("42846280183517070527831839425882145521227251250327", 50);
    TestVal+=UnsignedSuperUltraLong("55121603546981200581762165212827652751691296897789", 50);
    TestVal+=UnsignedSuperUltraLong("32238195734329339946437501907836945765883352399886", 50);
    TestVal+=UnsignedSuperUltraLong("75506164965184775180738168837861091527357929701337", 50);
    TestVal+=UnsignedSuperUltraLong("62177842752192623401942399639168044983993173312731", 50);
    TestVal+=UnsignedSuperUltraLong("32924185707147349566916674687634660915035914677504", 50);
    TestVal+=UnsignedSuperUltraLong("99518671430235219628894890102423325116913619626622", 50);
    TestVal+=UnsignedSuperUltraLong("73267460800591547471830798392868535206946944540724", 50);
    TestVal+=UnsignedSuperUltraLong("76841822524674417161514036427982273348055556214818", 50);
    TestVal+=UnsignedSuperUltraLong("97142617910342598647204516893989422179826088076852", 50);
    TestVal+=UnsignedSuperUltraLong("87783646182799346313767754307809363333018982642090", 50);
    TestVal+=UnsignedSuperUltraLong("10848802521674670883215120185883543223812876952786", 50);
    TestVal+=UnsignedSuperUltraLong("71329612474782464538636993009049310363619763878039", 50);
    TestVal+=UnsignedSuperUltraLong("62184073572399794223406235393808339651327408011116", 50);
    TestVal+=UnsignedSuperUltraLong("66627891981488087797941876876144230030984490851411", 50);
    TestVal+=UnsignedSuperUltraLong("60661826293682836764744779239180335110989069790714", 50);
    TestVal+=UnsignedSuperUltraLong("85786944089552990653640447425576083659976645795096", 50);
    TestVal+=UnsignedSuperUltraLong("66024396409905389607120198219976047599490197230297", 50);
    TestVal+=UnsignedSuperUltraLong("64913982680032973156037120041377903785566085089252", 50);
    TestVal+=UnsignedSuperUltraLong("16730939319872750275468906903707539413042652315011", 50);
    TestVal+=UnsignedSuperUltraLong("94809377245048795150954100921645863754710598436791", 50);
    TestVal+=UnsignedSuperUltraLong("78639167021187492431995700641917969777599028300699", 50);
    TestVal+=UnsignedSuperUltraLong("15368713711936614952811305876380278410754449733078", 50);
    TestVal+=UnsignedSuperUltraLong("40789923115535562561142322423255033685442488917353", 50);
    TestVal+=UnsignedSuperUltraLong("44889911501440648020369068063960672322193204149535", 50);
    TestVal+=UnsignedSuperUltraLong("41503128880339536053299340368006977710650566631954", 50);
    TestVal+=UnsignedSuperUltraLong("81234880673210146739058568557934581403627822703280", 50);
    TestVal+=UnsignedSuperUltraLong("82616570773948327592232845941706525094512325230608", 50);
    TestVal+=UnsignedSuperUltraLong("22918802058777319719839450180888072429661980811197", 50);
    TestVal+=UnsignedSuperUltraLong("77158542502016545090413245809786882778948721859617", 50);
    TestVal+=UnsignedSuperUltraLong("72107838435069186155435662884062257473692284509516", 50);
    TestVal+=UnsignedSuperUltraLong("20849603980134001723930671666823555245252804609722", 50);
    TestVal+=UnsignedSuperUltraLong("53503534226472524250874054075591789781264330331690", 50);

    char MyTestCharArr[UnsignedSuperUltraLong::kMaxTotalDigits];
    TestVal.ToCharArr(MyTestCharArr);
    cout << "First ten digits: ";
    for (int i = 0; i < 10; ++i)
    {
        cout << MyTestCharArr[i];
    }
    cout << endl;
}

void Problem14() {
    cout << "Which starting number, under one million, produces the longest (Collatz Sequence) chain?" << endl;

    unordered_map<unsigned long long, unsigned long long> CachedSequenceMap;
    CachedSequenceMap[1] = 1;
    unsigned long StartingNumberLongestChain = 1;

    for (unsigned long i = 2; i < 1000000; ++i)
    {
        //cout << "On index " << i << endl;
        auto it = CachedSequenceMap.find(i);
        if (it == CachedSequenceMap.end())
        {
            GetCollatzSequenceLength(i, CachedSequenceMap);
        }
        if (CachedSequenceMap[i] > CachedSequenceMap[StartingNumberLongestChain])
        {
            cout << "Updating longest chain to (index = " << i << ", number = " << CachedSequenceMap[i] << ")" << endl;
            StartingNumberLongestChain = i;
        }
    }
    
    cout << "Starting number: " << StartingNumberLongestChain << endl;
}

void Problem15() {
    cout << "How many such routes are there through a 20x20 grid?" << endl;
    const unsigned int kGridSize = 20;
    // I wrote out a function to calculate this by navigating all paths, commented out below.
    // unsigned long long TotalRoutes = GetTotalRoutesForGrid(kGridSize, 0, 0);

    // It was not efficient and I figured there was an equation so I played around with the results for grid sizes 1-5 and found how they related in a formula:
    // (Size, Routes)
    // (1, 2)
    // (2, 6)
    // (3, 20)
    // (4, 70)
    // (5, 252)
    // After playing with numbers, mostly focusing on factorials, etc. I got this equation to solve it (where x is width of grid):
    // Routes = (2x)! / ((x!)^2)
    // This can further be simplified down, by extrapolating out factorials (this is going to help us get around int sizes):
    // ((2x * (2x-1) * [...] * (x + 1))(x!)) / ((x!)(x!)) ->
    // (2x * (2x-1) * [...] * (x + 1)) / (x!)
    // Okay, we are getting somewhere, but this can actually be simplified even further.
    // We know every even value in the numerator is equal to double half of the denominator values. For example with 4:
    // (8 * 7 * 6 * 5) / (4 * 3 * 2 *1) -> (2 * 7 * 2 * 5) / (1 * 1 * 2 * 1)
    // or, rather:
    // ((7 * 5) * 2^2) / (2!)
    // So now, lets make it a bit more of an algorithm.
    // (FactorialUpperHalfOnlyOdds(2x) * 2^Ceil(x/2)) / (Floor(x/2)!)
    // Now we can actually do this an efficient way and get around obscenely large numbers.
    float HalfGridSize = kGridSize / 2.0;
    unsigned long long NumeratorOddFactorial = (kGridSize * 2) - 1;
    for (int i = NumeratorOddFactorial-2; i > kGridSize; i -= 2)
    {
        NumeratorOddFactorial *= i;
    }
    unsigned long long DenominatorHalfFactorial = floor(HalfGridSize);
    for (int i = DenominatorHalfFactorial-1; i > 0; --i)
    {
        DenominatorHalfFactorial *= i;
    }
    unsigned long long TotalRoutes = (NumeratorOddFactorial * pow(2, ceil(HalfGridSize))) / DenominatorHalfFactorial;
    cout << "Total routes: " << TotalRoutes << endl;
}

void Problem16() {
    cout << "What is the sum of the digits of the number 2^1000?" << endl;
    
    unsigned int DigitSum = 0;
    // Not planning on making this one super scalable.
    // Going to make an array to hold different sections of numbers as I multiply out the the 2^1000.
    // Keeping each item in array as unsigned long so I can use ltoa (34 is number needed to hold values up to e301 capped at e9 each)
    unsigned long ArrayOfInts[34] = {0};
    ArrayOfInts[0] = 2;
    unsigned int MaxIdxSoFar = 0;
    // Going to get a constant for 10^9 to cap out each array index.
    const unsigned long  kTenTo9 = 1000000000;
    for(int i = 2; i <= 1000; ++i)
    {
        unsigned int Overflow = 0;
        for (int j = 0; j <= MaxIdxSoFar; ++j)
        {
            ArrayOfInts[j] = (ArrayOfInts[j] * 2) + Overflow;
            if (ArrayOfInts[j] >= kTenTo9)
            {
                ArrayOfInts[j] -= kTenTo9;
                Overflow = 1;
            }
            else
            {
                Overflow = 0;
            }
        }
        if (Overflow == 1)
        {
            ++MaxIdxSoFar;
            ArrayOfInts[MaxIdxSoFar] = 1;
        }
    }
    for (int i = 0; i <= MaxIdxSoFar; ++i)
    {
        char Buff[10];
        ltoa(ArrayOfInts[i], Buff, 10);
        for (int j = 0; j < 10; ++j)
        {
            if (Buff[j] == '\0') break;
            int CurDigitVal = Buff[j] - '0';
            if (CurDigitVal > 0 && CurDigitVal <= 9)
            {
                DigitSum += CurDigitVal;
            }
        }
    }

    cout << "Leading digits: " << ArrayOfInts[MaxIdxSoFar] << endl;
    cout << "Next digits: " << ArrayOfInts[MaxIdxSoFar-1] << endl;
    cout << "Next digits: " << ArrayOfInts[MaxIdxSoFar-2] << endl;

    cout << "Digit sum: " << DigitSum << endl;
}

void Problem17() {
    cout << "If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?" << endl;
    
    unsigned int LetterTotal = 0;

    // Okay so I *could* do something that does a number to word generation and everything.
    // Instead I'm just going to turn it into an algorithm, since we know the rules and can just do it for numbers from 1-1000.

    const unsigned int OneLen = 3;
    const unsigned int TwoLen = 3;
    const unsigned int ThreeLen = 5;
    const unsigned int FourLen = 4;
    const unsigned int FiveLen = 4;
    const unsigned int SixLen = 3;
    const unsigned int SevenLen = 5;
    const unsigned int EightLen = 5;
    const unsigned int NineLen = 4;
    const unsigned int TenLen = 3;
    const unsigned int ElevenLen = 6;
    const unsigned int TwelveLen = 6;
    const unsigned int TeenLen = 4;
    const unsigned int TwentyLen = 6;
    const unsigned int ThirtyLen = 6;
    const unsigned int FortyLen = 5;
    const unsigned int FiftyLen = 5;
    const unsigned int SixtyLen = 5;
    const unsigned int SeventyLen = 7;
    const unsigned int EightyLen = 6;
    const unsigned int NinetyLen = 6;
    const unsigned int HundredLen = 7;
    const unsigned int ThousandLen = 8;
    const unsigned int AndLen = 3;

    // Start by figuring out the number of times that 1-9 will appear
    // In ones place: 90x (1-9, 21-99) = repeated 9 times every 100 numbers
    // In hundreds place: 100x (100-199)
    // Total 190x
    unsigned int OnesPlacesTotal = (OneLen + TwoLen + ThreeLen + FourLen + FiveLen + SixLen + SevenLen + EightLen + NineLen);
    LetterTotal += OnesPlacesTotal * 190;
    // 10-19 will only appear once every 100 numbers or 10x.
    // Subtract 1 from ThreeLen for "thir", 1 from FiveLen for "fif", and 1 from EightLen for "eigh"
    unsigned int TenToNineteenTotal = (TenLen + ElevenLen + TwelveLen + (ThreeLen - 1) + FourLen + (FiveLen - 1) + SixLen + SevenLen + (EightLen - 1) + NineLen + (TeenLen * 7));
    LetterTotal += TenToNineteenTotal * 10;
    // Now for the tens place for 20-99
    // 100x, done 10 times every 100 numbers
    unsigned int TensPlacesTotal = (TwentyLen + ThirtyLen + FortyLen + FiftyLen + SixtyLen + SeventyLen + EightyLen + NinetyLen);
    LetterTotal += TensPlacesTotal * 100;
    // 'hundred' will be in every number from 100-999, so 900x
    LetterTotal += HundredLen * 900;
    // 'and' will be in every number from 101-999, excluding even hundreds so 891x
    LetterTotal += AndLen * 891;
    // All that's left is one thousand
    LetterTotal += OneLen + ThousandLen;

    cout << "Total Letters: " << LetterTotal << endl;
}

void Problem18() {
    cout << "Find the maximum total from top to bottom of the triangle below:" << endl;

    const unsigned int kPyramidDepth = 15;

    struct PyramidNode {
        tuple<unsigned int, unsigned int> NodeXY;
        unsigned int NodeVal = 0;
        unsigned int NodeSum = 0;
        PyramidNode* PrevMaxNode;

        PyramidNode() {}

        PyramidNode(unsigned int NodeVal, tuple<unsigned int, unsigned int> NodeXY): NodeVal(NodeVal), NodeXY(NodeXY), NodeSum(NodeVal) { }

        void SetPrevMaxNode(PyramidNode* InPrevMaxNode) {
            PrevMaxNode = InPrevMaxNode;
            NodeSum = NodeVal;
            if (PrevMaxNode) {
                NodeSum += PrevMaxNode->NodeSum;
            }
        }

    };

    PyramidNode PyramidNodes[kPyramidDepth][kPyramidDepth];

    unsigned int NumberPyramid[kPyramidDepth][kPyramidDepth] = {

        {75},
        {95, 64},
        {17, 47, 82},
        {18, 35, 87, 10},
        {20,  4, 82, 47, 65},
        {19,  1, 23, 75,  3, 34},
        {88,  2, 77, 73,  7, 63, 67},
        {99, 65,  4, 28,  6, 16, 70, 92},
        {41, 41, 26, 56, 83, 40, 80, 70, 33},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        { 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}

    };

    unsigned int MaxPathSum = 0;

    tuple<unsigned int, unsigned int> CurCoord(0, 0);
    PyramidNodes[0][0] = PyramidNode(NumberPyramid[0][0], CurCoord);

    for (int y = 1; y < kPyramidDepth; ++y) {
        for (int x = 0; x <= y; ++x) {
            get<0>(CurCoord) = x;
            get<1>(CurCoord) = y;
            PyramidNodes[y][x] = PyramidNode(NumberPyramid[y][x], CurCoord);
            if (x == 0 || PyramidNodes[y-1][x].NodeSum > PyramidNodes[y-1][x-1].NodeSum) {
                PyramidNodes[y][x].SetPrevMaxNode(&PyramidNodes[y-1][x]);
            }
            else if (x == y){
                PyramidNodes[y][x].SetPrevMaxNode(&PyramidNodes[y-1][x-1]);
            }
            else if (PyramidNodes[y-1][x].NodeSum > PyramidNodes[y-1][x-1].NodeSum){
                PyramidNodes[y][x].SetPrevMaxNode(&PyramidNodes[y-1][x]);
            }
            else {
                PyramidNodes[y][x].SetPrevMaxNode(&PyramidNodes[y-1][x-1]);
            }
            if (y == kPyramidDepth-1 && PyramidNodes[y][x].NodeSum > MaxPathSum) {
                MaxPathSum = PyramidNodes[y][x].NodeSum;
            }
        }
    }

    cout << "Max Path Sum: " << MaxPathSum << endl;
}

void Problem19() {
    cout << "How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?" << endl;

    unsigned int NumSundays = 0;

    unsigned int CurWeekday = 2; // 1/1/1901 is a Tuesday and this will be 0-7 Sunday-Saturday

    unsigned int NumDays = 0;
    for(int Year = 1901; Year <= 2000; ++Year) {
        for(int Month = 1; Month <= 12; ++Month) {
            CurWeekday = (CurWeekday + NumDays) % 7;
            if (CurWeekday == 0) {
                ++NumSundays;
            }
            //Updating NumDays for next iteration
            if (Month == 4 or Month == 6 or Month == 9 or Month == 11) {
                NumDays = 30;
            }
            else if (Month == 2) {
                if (Year % 4 == 0) {
                    NumDays = 29;
                }
                else {
                    NumDays = 28;
                }
            }
            else {
                NumDays = 31;
            }
        }
    }

    cout << "Sundays: " << NumSundays << endl;
}

void Problem20() {
    cout << "Find the sum of the digits in the number 100!." << endl;
    auto t0 = chrono::steady_clock::now();
    unsigned int FactorialDigitSum = 0;
    SuperUltraLong FactorialRunningTotal = SuperUltraLong(1);
    char MyTestCharArr[SuperUltraLong::kMaxTotalInts+1];

    for (int i = 99; i > 1; --i) {
        cout << "i: " << i << endl;
        if (i % 10 == 0) {
            FactorialRunningTotal = FactorialRunningTotal * (i / 10);
        }
        else {
            FactorialRunningTotal = FactorialRunningTotal * i;
        }
        if (FactorialRunningTotal.IntArray[0] == 0)
        {
            for (int j = 1; j < SuperUltraLong::kMaxTotalInts; ++j)
            {
                if (FactorialRunningTotal.IntArray[j] != 0)
                {
                    FactorialRunningTotal.ShiftRight(j);
                    break;
                }
            }
        }
    }
    ToCharArr(FactorialRunningTotal, MyTestCharArr);
    cout << "End Factorial: " << MyTestCharArr << endl;
    for (int i = 0; i < SuperUltraLong::kMaxTotalInts; ++i)
    {
        FactorialDigitSum += FactorialRunningTotal.IntArray[i];
    }
    // work
    auto t1 = chrono::steady_clock::now();
    std::cout << chrono::duration_cast<chrono::milliseconds>(t1-t0).count() << "ms elapsed" << std::endl;
    cout << "Factorial Digit Sum: " << FactorialDigitSum << endl;
}

void Problem67() {
    cout << "Find the maximum total from top to bottom of the triangle of 100 depth:" << endl;

    const unsigned int kPyramidDepth = 100;

    struct PyramidNode {
        tuple<unsigned int, unsigned int> NodeXY;
        unsigned long long NodeVal = 0;
        unsigned long long NodeSum = 0;
        PyramidNode* PrevMaxNode;

        PyramidNode() {}

        PyramidNode(unsigned long long NodeVal, tuple<unsigned int, unsigned int> NodeXY): NodeVal(NodeVal), NodeXY(NodeXY), NodeSum(NodeVal) { }

        void SetPrevMaxNode(PyramidNode* InPrevMaxNode) {
            PrevMaxNode = InPrevMaxNode;
            NodeSum = NodeVal;
            if (PrevMaxNode) {
                NodeSum += PrevMaxNode->NodeSum;
            }
        }

    };

    PyramidNode PyramidNodes[kPyramidDepth][kPyramidDepth];

    unsigned int NumberPyramid[kPyramidDepth][kPyramidDepth] = {

        {59},
        {73, 41},
        {52, 40,  9},
        {26, 53,  6, 34},
        {10, 51, 87, 86, 81},
        {61, 95, 66, 57, 25, 68},
        {90, 81, 80, 38, 92, 67, 73},
        {30, 28, 51, 76, 81, 18, 75, 44},
        {84, 14, 95, 87, 62, 81, 17, 78, 58},
        {21, 46, 71, 58,  2, 79, 62, 39, 31,  9},
        {56, 34, 35, 53, 78, 31, 81, 18, 90, 93, 15},
        {78, 53,  4, 21, 84, 93, 32, 13, 97, 11, 37, 51},
        {45,  3, 81, 79,  5, 18, 78, 86, 13, 30, 63, 99, 95},
        {39, 87, 96, 28,  3, 38, 42, 17, 82, 87, 58,  7, 22, 57},
        { 6, 17, 51, 17,  7, 93,  9,  7, 75, 97, 95, 78, 87,  8, 53},
        {67, 66, 59, 60, 88, 99, 94, 65, 55, 77, 55, 34, 27, 53, 78, 28},
        {76, 40, 41,  4, 87, 16,  9, 42, 75, 69, 23, 97, 30, 60, 10, 79, 87},
        {12, 10, 44, 26, 21, 36, 32, 84, 98, 60, 13, 12, 36, 16, 63, 31, 91, 35},
        {70, 39,  6,  5, 55, 27, 38, 48, 28, 22, 34, 35, 62, 62, 15, 14, 94, 89, 86},
        {66, 56, 68, 84, 96, 21, 34, 34, 34, 81, 62, 40, 65, 54, 62,  5, 98,  3,  2, 60},
        {38, 89, 46, 37, 99, 54, 34, 53, 36, 14, 70, 26,  2, 90, 45, 13, 31, 61, 83, 73, 47},
        {36, 10, 63, 96, 60, 49, 41,  5, 37, 42, 14, 58, 84, 93, 96, 17,  9, 43,  5, 43,  6, 59},
        {66, 57, 87, 57, 61, 28, 37, 51, 84, 73, 79, 15, 39, 95, 88, 87, 43, 39, 11, 86, 77, 74, 18},
        {54, 42,  5, 79, 30, 49, 99, 73, 46, 37, 50,  2, 45,  9, 54, 52, 27, 95, 27, 65, 19, 45, 26, 45},
        {71, 39, 17, 78, 76, 29, 52, 90, 18, 99, 78, 19, 35, 62, 71, 19, 23, 65, 93, 85, 49, 33, 75,  9,  2},
        {33, 24, 47, 61, 60, 55, 32, 88, 57, 55, 91, 54, 46, 57,  7, 77, 98, 52, 80, 99, 24, 25, 46, 78, 79,  5},
        {92,  9, 13, 55, 10, 67, 26, 78, 76, 82, 63, 49, 51, 31, 24, 68,  5, 57,  7, 54, 69, 21, 67, 43, 17, 63, 12},
        {24, 59,  6,  8, 98, 74, 66, 26, 61, 60, 13,  3,  9,  9, 24, 30, 71,  8, 88, 70, 72, 70, 29, 90, 11, 82, 41, 34},
        {66, 82, 67,  4, 36, 60, 92, 77, 91, 85, 62, 49, 59, 61, 30, 90, 29, 94, 26, 41, 89,  4, 53, 22, 83, 41,  9, 74, 90},
        {48, 28, 26, 37, 28, 52, 77, 26, 51, 32, 18, 98, 79, 36, 62, 13, 17,  8, 19, 54, 89, 29, 73, 68, 42, 14,  8, 16, 70, 37},
        {37, 60, 69, 70, 72, 71,  9, 59, 13, 60, 38, 13, 57, 36,  9, 30, 43, 89, 30, 39, 15,  2, 44, 73,  5, 73, 26, 63, 56, 86, 12},
        {55, 55, 85, 50, 62, 99, 84, 77, 28, 85,  3, 21, 27, 22, 19, 26, 82, 69, 54,  4, 13,  7, 85, 14,  1, 15, 70, 59, 89, 95, 10, 19},
        { 4,  9, 31, 92, 91, 38, 92, 86, 98, 75, 21,  5, 64, 42, 62, 84, 36, 20, 73, 42, 21, 23, 22, 51, 51, 79, 25, 45, 85, 53,  3, 43, 22},
        {75, 63,  2, 49, 14, 12, 89, 14, 60, 78, 92, 16, 44, 82, 38, 30, 72, 11, 46, 52, 90, 27,  8, 65, 78,  3, 85, 41, 57, 79, 39, 52, 33, 48},
        {78, 27, 56, 56, 39, 13, 19, 43, 86, 72, 58, 95, 39,  7,  4, 34, 21, 98, 39, 15, 39, 84, 89, 69, 84, 46, 37, 57, 59, 35, 59, 50, 26, 15, 93},
        {42, 89, 36, 27, 78, 91, 24, 11, 17, 41,  5, 94,  7, 69, 51, 96,  3, 96, 47, 90, 90, 45, 91, 20, 50, 56, 10, 32, 36, 49,  4, 53, 85, 92, 25, 65},
        {52,  9, 61, 30, 61, 97, 66, 21, 96, 92, 98, 90,  6, 34, 96, 60, 32, 69, 68, 33, 75, 84, 18, 31, 71, 50, 84, 63,  3,  3, 19, 11, 28, 42, 75, 45, 45},
        {61, 31, 61, 68, 96, 34, 49, 39,  5, 71, 76, 59, 62, 67,  6, 47, 96, 99, 34, 21, 32, 47, 52,  7, 71, 60, 42, 72, 94, 56, 82, 83, 84, 40, 94, 87, 82, 46},
        { 1, 20, 60, 14, 17, 38, 26, 78, 66, 81, 45, 95, 18, 51, 98, 81, 48, 16, 53, 88, 37, 52, 69, 95, 72, 93, 22, 34, 98, 20, 54, 27, 73, 61, 56, 63, 60, 34, 63},
        {93, 42, 94, 83, 47, 61, 27, 51, 79, 79, 45,  1, 44, 73, 31, 70, 83, 42, 88, 25, 53, 51, 30, 15, 65, 94, 80, 44, 61, 84, 12, 77,  2, 62,  2, 65, 94, 42, 14, 94},
        {32, 73,  9, 67, 68, 29, 74, 98, 10, 19, 85, 48, 38, 31, 85, 67, 53, 93, 93, 77, 47, 67, 39, 72, 94, 53, 18, 43, 77, 40, 78, 32, 29, 59, 24,  6,  2, 83, 50, 60, 66},
        {32,  1, 44, 30, 16, 51, 15, 81, 98, 15, 10, 62, 86, 79, 50, 62, 45, 60, 70, 38, 31, 85, 65, 61, 64,  6, 69, 84, 14, 22, 56, 43,  9, 48, 66, 69, 83, 91, 60, 40, 36, 61},
        {92, 48, 22, 99, 15, 95, 64, 43,  1, 16, 94,  2, 99, 19, 17, 69, 11, 58, 97, 56, 89, 31, 77, 45, 67, 96, 12, 73,  8, 20, 36, 47, 81, 44, 50, 64, 68, 85, 40, 81, 85, 52,  9},
        {91, 35, 92, 45, 32, 84, 62, 15, 19, 64, 21, 66,  6,  1, 52, 80, 62, 59, 12, 25, 88, 28, 91, 50, 40, 16, 22, 99, 92, 79, 87, 51, 21, 77, 74, 77,  7, 42, 38, 42, 74, 83,  2,  5},
        {46, 19, 77, 66, 24, 18,  5, 32,  2, 84, 31, 99, 92, 58, 96, 72, 91, 36, 62, 99, 55, 29, 53, 42, 12, 37, 26, 58, 89, 50, 66, 19, 82, 75, 12, 48, 24, 87, 91, 85,  2,  7,  3, 76, 86},
        {99, 98, 84, 93,  7, 17, 33, 61, 92, 20, 66, 60, 24, 66, 40, 30, 67,  5, 37, 29, 24, 96,  3, 27, 70, 62, 13,  4, 45, 47, 59, 88, 43, 20, 66, 15, 46, 92, 30,  4, 71, 66, 78, 70, 53, 99},
        {67, 60, 38,  6, 88,  4, 17, 72, 10, 99, 71,  7, 42, 25, 54,  5, 26, 64, 91, 50, 45, 71,  6, 30, 67, 48, 69, 82,  8, 56, 80, 67, 18, 46, 66, 63,  1, 20,  8, 80, 47,  7, 91, 16,  3, 79, 87},
        {18, 54, 78, 49, 80, 48, 77, 40, 68, 23, 60, 88, 58, 80, 33, 57, 11, 69, 55, 53, 64,  2, 94, 49, 60, 92, 16, 35, 81, 21, 82, 96, 25, 24, 96, 18,  2,  5, 49,  3, 50, 77,  6, 32, 84, 27, 18, 38},
        {68,  1, 50,  4,  3, 21, 42, 94, 53, 24, 89,  5, 92, 26, 52, 36, 68, 11, 85,  1,  4, 42,  2, 45, 15,  6, 50,  4, 53, 73, 25, 74, 81, 88, 98, 21, 67, 84, 79, 97, 99, 20, 95,  4, 40, 46,  2, 58, 87},
        {94, 10,  2, 78, 88, 52, 21,  3, 88, 60,  6, 53, 49, 71, 20, 91, 12, 65,  7, 49, 21, 22, 11, 41, 58, 99, 36, 16,  9, 48, 17, 24, 52, 36, 23, 15, 72, 16, 84, 56,  2, 99, 43, 76, 81, 71, 29, 39, 49, 17},
        {64, 39, 59, 84, 86, 16, 17, 66,  3,  9, 43,  6, 64, 18, 63, 29, 68,  6, 23,  7, 87, 14, 26, 35, 17, 12, 98, 41, 53, 64, 78, 18, 98, 27, 28, 84, 80, 67, 75, 62, 10, 11, 76, 90, 54, 10,  5, 54, 41, 39, 66},
        {43, 83, 18, 37, 32, 31, 52, 29, 95, 47,  8, 76, 35, 11,  4, 53, 35, 43, 34, 10, 52, 57, 12, 36, 20, 39, 40, 55, 78, 44,  7, 31, 38, 26,  8, 15, 56, 88, 86,  1, 52, 62, 10, 24, 32,  5, 60, 65, 53, 28, 57, 99},
        { 3, 50,  3, 52,  7, 73, 49, 92, 66, 80,  1, 46,  8, 67, 25, 36, 73, 93,  7, 42, 25, 53, 13, 96, 76, 83, 87, 90, 54, 89, 78, 22, 78, 91, 73, 51, 69,  9, 79, 94, 83, 53,  9, 40, 69, 62, 10, 79, 49, 47,  3, 81, 30},
        {71, 54, 73, 33, 51, 76, 59, 54, 79, 37, 56, 45, 84, 17, 62, 21, 98, 69, 41, 95, 65, 24, 39, 37, 62,  3, 24, 48, 54, 64, 46, 82, 71, 78, 33, 67,  9, 16, 96, 68, 52, 74, 79, 68, 32, 21, 13, 78, 96, 60,  9, 69, 20, 36},
        {73, 26, 21, 44, 46, 38, 17, 83, 65, 98,  7, 23, 52, 46, 61, 97, 33, 13, 60, 31, 70, 15, 36, 77, 31, 58, 56, 93, 75, 68, 21, 36, 69, 53, 90, 75, 25, 82, 39, 50, 65, 94, 29, 30, 11, 33, 11, 13, 96,  2, 56, 47,  7, 49,  2},
        {76, 46, 73, 30, 10, 20, 60, 70, 14, 56, 34, 26, 37, 39, 48, 24, 55, 76, 84, 91, 39, 86, 95, 61, 50, 14, 53, 93, 64, 67, 37, 31, 10, 84, 42, 70, 48, 20, 10, 72, 60, 61, 84, 79, 69, 65, 99, 73, 89, 25, 85, 48, 92, 56, 97, 16},
        { 3, 14, 80, 27, 22, 30, 44, 27, 67, 75, 79, 32, 51, 54, 81, 29, 65, 14, 19,  4, 13, 82,  4, 91, 43, 40, 12, 52, 29, 99,  7, 76, 60, 25,  1,  7, 61, 71, 37, 92, 40, 47, 99, 66, 57,  1, 43, 44, 22, 40, 53, 53,  9, 69, 26, 81,  7},
        {49, 80, 56, 90, 93, 87, 47, 13, 75, 28, 87, 23, 72, 79, 32, 18, 27, 20, 28, 10, 37, 59, 21, 18, 70,  4, 79, 96,  3, 31, 45, 71, 81,  6, 14, 18, 17,  5, 31, 50, 92, 79, 23, 47,  9, 39, 47, 91, 43, 54, 69, 47, 42, 95, 62, 46, 32, 85},
        {37, 18, 62, 85, 87, 28, 64,  5, 77, 51, 47, 26, 30, 65,  5, 70, 65, 75, 59, 80, 42, 52, 25, 20, 44, 10, 92, 17, 71, 95, 52, 14, 77, 13, 24, 55, 11, 65, 26, 91,  1, 30, 63, 15, 49, 48, 41, 17, 67, 47,  3, 68, 20, 90, 98, 32,  4, 40, 68},
        {90, 51, 58, 60,  6, 55, 23, 68,  5, 19, 76, 94, 82, 36, 96, 43, 38, 90, 87, 28, 33, 83,  5, 17, 70, 83, 96, 93,  6,  4, 78, 47, 80,  6, 23, 84, 75, 23, 87, 72, 99, 14, 50, 98, 92, 38, 90, 64, 61, 58, 76, 94, 36, 66, 87, 80, 51, 35, 61, 38},
        {57, 95, 64,  6, 53, 36, 82, 51, 40, 33, 47, 14,  7, 98, 78, 65, 39, 58, 53,  6, 50, 53,  4, 69, 40, 68, 36, 69, 75, 78, 75, 60,  3, 32, 39, 24, 74, 47, 26, 90, 13, 40, 44, 71, 90, 76, 51, 24, 36, 50, 25, 45, 70, 80, 61, 80, 61, 43, 90, 64, 11},
        {18, 29, 86, 56, 68, 42, 79, 10, 42, 44, 30, 12, 96, 18, 23, 18, 52, 59,  2, 99, 67, 46, 60, 86, 43, 38, 55, 17, 44, 93, 42, 21, 55, 14, 47, 34, 55, 16, 49, 24, 23, 29, 96, 51, 55, 10, 46, 53, 27, 92, 27, 46, 63, 57, 30, 65, 43, 27, 21, 20, 24, 83},
        {81, 72, 93, 19, 69, 52, 48,  1, 13, 83, 92, 69, 20, 48, 69, 59, 20, 62,  5, 42, 28, 89, 90, 99, 32, 72, 84, 17,  8, 87, 36,  3, 60, 31, 36, 36, 81, 26, 97, 36, 48, 54, 56, 56, 27, 16, 91,  8, 23, 11, 87, 99, 33, 47,  2, 14, 44, 73, 70, 99, 43, 35, 33},
        {90, 56, 61, 86, 56, 12, 70, 59, 63, 32,  1, 15, 81, 47, 71, 76, 95, 32, 65, 80, 54, 70, 34, 51, 40, 45, 33,  4, 64, 55, 78, 68, 88, 47, 31, 47, 68, 87,  3, 84, 23, 44, 89, 72, 35,  8, 31, 76, 63, 26, 90, 85, 96, 67, 65, 91, 19, 14, 17, 86,  4, 71, 32, 95},
        {37, 13,  4, 22, 64, 37, 37, 28, 56, 62, 86, 33,  7, 37, 10, 44, 52, 82, 52,  6, 19, 52, 57, 75, 90, 26, 91, 24,  6, 21, 14, 67, 76, 30, 46, 14, 35, 89, 89, 41,  3, 64, 56, 97, 87, 63, 22, 34,  3, 79, 17, 45, 11, 53, 25, 56, 96, 61, 23, 18, 63, 31, 37, 37, 47},
        {77, 23, 26, 70, 72, 76, 77,  4, 28, 64, 71, 69, 14, 85, 96, 54, 95, 48,  6, 62, 99, 83, 86, 77, 97, 75, 71, 66, 30, 19, 57, 90, 33,  1, 60, 61, 14, 12, 90, 99, 32, 77, 56, 41, 18, 14, 87, 49, 10, 14, 90, 64, 18, 50, 21, 74, 14, 16, 88,  5, 45, 73, 82, 47, 74, 44},
        {22, 97, 41, 13, 34, 31, 54, 61, 56, 94,  3, 24, 59, 27, 98, 77,  4,  9, 37, 40, 12, 26, 87,  9, 71, 70,  7, 18, 64, 57, 80, 21, 12, 71, 83, 94, 60, 39, 73, 79, 73, 19, 97, 32, 64, 29, 41,  7, 48, 84, 85, 67, 12, 74, 95, 20, 24, 52, 41, 67, 56, 61, 29, 93, 35, 72, 69},
        {72, 23, 63, 66,  1, 11,  7, 30, 52, 56, 95, 16, 65, 26, 83, 90, 50, 74, 60, 18, 16, 48, 43, 77, 37, 11, 99, 98, 30, 94, 91, 26, 62, 73, 45, 12, 87, 73, 47, 27,  1, 88, 66, 99, 21, 41, 95, 80,  2, 53, 23, 32, 61, 48, 32, 43, 43, 83, 14, 66, 95, 91, 19, 81, 80, 67, 25, 88},
        { 8, 62, 32, 18, 92, 14, 83, 71, 37, 96, 11, 83, 39, 99,  5, 16, 23, 27, 10, 67,  2, 25, 44, 11, 55, 31, 46, 64, 41, 56, 44, 74, 26, 81, 51, 31, 45, 85, 87,  9, 81, 95, 22, 28, 76, 69, 46, 48, 64, 87, 67, 76, 27, 89, 31, 11, 74, 16, 62,  3, 60, 94, 42, 47,  9, 34, 94, 93, 72},
        {56, 18, 90, 18, 42, 17, 42, 32, 14, 86,  6, 53, 33, 95, 99, 35, 29, 15, 44, 20, 49, 59, 25, 54, 34, 59, 84, 21, 23, 54, 35, 90, 78, 16, 93, 13, 37, 88, 54, 19, 86, 67, 68, 55, 66, 84, 65, 42, 98, 37, 87, 56, 33, 28, 58, 38, 28, 38, 66, 27, 52, 21, 81, 15,  8, 22, 97, 32, 85, 27},
        {91, 53, 40, 28, 13, 34, 91, 25,  1, 63, 50, 37, 22, 49, 71, 58, 32, 28, 30, 18, 68, 94, 23, 83, 63, 62, 94, 76, 80, 41, 90, 22, 82, 52, 29, 12, 18, 56, 10,  8, 35, 14, 37, 57, 23, 65, 67, 40, 72, 39, 93, 39, 70, 89, 40, 34,  7, 46, 94, 22, 20,  5, 53, 64, 56, 30,  5, 56, 61, 88, 27},
        {23, 95, 11, 12, 37, 69, 68, 24, 66, 10, 87, 70, 43, 50, 75,  7, 62, 41, 83, 58, 95, 93, 89, 79, 45, 39,  2, 22,  5, 22, 95, 43, 62, 11, 68, 29, 17, 40, 26, 44, 25, 71, 87, 16, 70, 85, 19, 25, 59, 94, 90, 41, 41, 80, 61, 70, 55, 60, 84, 33, 95, 76, 42, 63, 15,  9,  3, 40, 38, 12,  3, 32},
        { 9, 84, 56, 80, 61, 55, 85, 97, 16, 94, 82, 94, 98, 57, 84, 30, 84, 48, 93, 90, 71,  5, 95, 90, 73, 17, 30, 98, 40, 64, 65, 89,  7, 79,  9, 19, 56, 36, 42, 30, 23, 69, 73, 72,  7,  5, 27, 61, 24, 31, 43, 48, 71, 84, 21, 28, 26, 65, 65, 59, 65, 74, 77, 20, 10, 81, 61, 84, 95,  8, 52, 23, 70},
        {47, 81, 28,  9, 98, 51, 67, 64, 35, 51, 59, 36, 92, 82, 77, 65, 80, 24, 72, 53, 22,  7, 27, 10, 21, 28, 30, 22, 48, 82, 80, 48, 56, 20, 14, 43, 18, 25, 50, 95, 90, 31, 77,  8,  9, 48, 44, 80, 90, 22, 93, 45, 82, 17, 13, 96, 25, 26,  8, 73, 34, 99,  6, 49, 24,  6, 83, 51, 40, 14, 15, 10, 25,  1},
        {54, 25, 10, 81, 30, 64, 24, 74, 75, 80, 36, 75, 82, 60, 22, 69, 72, 91, 45, 67,  3, 62, 79, 54, 89, 74, 44, 83, 64, 96, 66, 73, 44, 30, 74, 50, 37,  5,  9, 97, 70,  1, 60, 46, 37, 91, 39, 75, 75, 18, 58, 52, 72, 78, 51, 81, 86, 52,  8, 97,  1, 46, 43, 66, 98, 62, 81, 18, 70, 93, 73,  8, 32, 46, 34},
        {96, 80, 82,  7, 59, 71, 92, 53, 19, 20, 88, 66,  3, 26, 26, 10, 24, 27, 50, 82, 94, 73, 63,  8, 51, 33, 22, 45, 19, 13, 58, 33, 90, 15, 22, 50, 36, 13, 55,  6, 35, 47, 82, 52, 33, 61, 36, 27, 28, 46, 98, 14, 73, 20, 73, 32, 16, 26, 80, 53, 47, 66, 76, 38, 94, 45,  2,  1, 22, 52, 47, 96, 64, 58, 52, 39},
        {88, 46, 23, 39, 74, 63, 81, 64, 20, 90, 33, 33, 76, 55, 58, 26, 10, 46, 42, 26, 74, 74, 12, 83, 32, 43,  9,  2, 73, 55, 86, 54, 85, 34, 28, 23, 29, 79, 91, 62, 47, 41, 82, 87, 99, 22, 48, 90, 20,  5, 96, 75, 95,  4, 43, 28, 81, 39, 81,  1, 28, 42, 78, 25, 39, 77, 90, 57, 58, 98, 17, 36, 73, 22, 63, 74, 51},
        {29, 39, 74, 94, 95, 78, 64, 24, 38, 86, 63, 87, 93,  6, 70, 92, 22, 16, 80, 64, 29, 52, 20, 27, 23, 50, 14, 13, 87, 15, 72, 96, 81, 22,  8, 49, 72, 30, 70, 24, 79, 31, 16, 64, 59, 21, 89, 34, 96, 91, 48, 76, 43, 53, 88,  1, 57, 80, 23, 81, 90, 79, 58,  1, 80, 87, 17, 99, 86, 90, 72, 63, 32, 69, 14, 28, 88, 69},
        {37, 17, 71, 95, 56, 93, 71, 35, 43, 45,  4, 98, 92, 94, 84, 96, 11, 30, 31, 27, 31, 60, 92,  3, 48,  5, 98, 91, 86, 94, 35, 90, 90,  8, 48, 19, 33, 28, 68, 37, 59, 26, 65, 96, 50, 68, 22,  7,  9, 49, 34, 31, 77, 49, 43,  6, 75, 17, 81, 87, 61, 79, 52, 26, 27, 72, 29, 50,  7, 98, 86,  1, 17, 10, 46, 64, 24, 18, 56},
        {51, 30, 25, 94, 88, 85, 79, 91, 40, 33, 63, 84, 49, 67, 98, 92, 15, 26, 75, 19, 82,  5, 18, 78, 65, 93, 61, 48, 91, 43, 59, 41, 70, 51, 22, 15, 92, 81, 67, 91, 46, 98, 11, 11, 65, 31, 66, 10, 98, 65, 83, 21,  5, 56,  5, 98, 73, 67, 46, 74, 69, 34,  8, 30,  5, 52,  7, 98, 32, 95, 30, 94, 65, 50, 24, 63, 28, 81, 99, 57},
        {19, 23, 61, 36,  9, 89, 71, 98, 65, 17, 30, 29, 89, 26, 79, 74, 94, 11, 44, 48, 97, 54, 81, 55, 39, 66, 69, 45, 28, 47, 13, 86, 15, 76, 74, 70, 84, 32, 36, 33, 79, 20, 78, 14, 41, 47, 89, 28, 81,  5, 99, 66, 81, 86, 38, 26,  6, 25, 13, 60, 54, 55, 23, 53, 27,  5, 89, 25, 23, 11, 13, 54, 59, 54, 56, 34, 16, 24, 53, 44,  6},
        {13, 40, 57, 72, 21, 15, 60,  8,  4, 19, 11, 98, 34, 45,  9, 97, 86, 71,  3, 15, 56, 19, 15, 44, 97, 31, 90,  4, 87, 87, 76,  8, 12, 30, 24, 62, 84, 28, 12, 85, 82, 53, 99, 52, 13, 94,  6, 65, 97, 86,  9, 50, 94, 68, 69, 74, 30, 67, 87, 94, 63,  7, 78, 27, 80, 36, 69, 41,  6, 92, 32, 78, 37, 82, 30,  5, 18, 87, 99, 72, 19, 99},
        {44, 20, 55, 77, 69, 91, 27, 31, 28, 81, 80, 27,  2,  7, 97, 23, 95, 98, 12, 25, 75, 29, 47, 71,  7, 47, 78, 39, 41, 59, 27, 76, 13, 15, 66, 61, 68, 35, 69, 86, 16, 53, 67, 63, 99, 85, 41, 56,  8, 28, 33, 40, 94, 76, 90, 85, 31, 70, 24, 65, 84, 65, 99, 82, 19, 25, 54, 37, 21, 46, 33,  2, 52, 99, 51, 33, 26,  4, 87,  2,  8, 18, 96},
        {54, 42, 61, 45, 91,  6, 64, 79, 80, 82, 32, 16, 83, 63, 42, 49, 19, 78, 65, 97, 40, 42, 14, 61, 49, 34,  4, 18, 25, 98, 59, 30, 82, 72, 26, 88, 54, 36, 21, 75,  3, 88, 99, 53, 46, 51, 55, 78, 22, 94, 34, 40, 68, 87, 84, 25, 30, 76, 25,  8, 92, 84, 42, 61, 40, 38,  9, 99, 40, 23, 29, 39, 46, 55, 10, 90, 35, 84, 56, 70, 63, 23, 91, 39},
        {52, 92,  3, 71, 89,  7,  9, 37, 68, 66, 58, 20, 44, 92, 51, 56, 13, 71, 79, 99, 26, 37,  2,  6, 16, 67, 36, 52, 58, 16, 79, 73, 56, 60, 59, 27, 44, 77, 94, 82, 20, 50, 98, 33,  9, 87, 94, 37, 40, 83, 64, 83, 58, 85, 17, 76, 53,  2, 83, 52, 22, 27, 39, 20, 48, 92, 45, 21,  9, 42, 24, 23, 12, 37, 52, 28, 50, 78, 79, 20, 86, 62, 73, 20, 59},
        {54, 96, 80, 15, 91, 90, 99, 70, 10,  9, 58, 90, 93, 50, 81, 99, 54, 38, 36, 10, 30, 11, 35, 84, 16, 45, 82, 18, 11, 97, 36, 43, 96, 79, 97, 65, 40, 48, 23, 19, 17, 31, 64, 52, 65, 65, 37, 32, 65, 76, 99, 79, 34, 65, 79, 27, 55, 33,  3,  1, 33, 27, 61, 28, 66,  8,  4, 70, 49, 46, 48, 83,  1, 45, 19, 96, 13, 81, 14, 21, 31, 79, 93, 85, 50,  5},
        {92, 92, 48, 84, 59, 98, 31, 53, 23, 27, 15, 22, 79, 95, 24, 76,  5, 79, 16, 93, 97, 89, 38, 89, 42, 83,  2, 88, 94, 95, 82, 21,  1, 97, 48, 39, 31, 78,  9, 65, 50, 56, 97, 61,  1,  7, 65, 27, 21, 23, 14, 15, 80, 97, 44, 78, 49, 35, 33, 45, 81, 74, 34,  5, 31, 57,  9, 38, 94,  7, 69, 54, 69, 32, 65, 68, 46, 68, 78, 90, 24, 28, 49, 51, 45, 86, 35},
        {41, 63, 89, 76, 87, 31, 86,  9, 46, 14, 87, 82, 22, 29, 47, 16, 13, 10, 70, 72, 82, 95, 48, 64, 58, 43, 13, 75, 42, 69, 21, 12, 67, 13, 64, 85, 58, 23, 98,  9, 37, 76,  5, 22, 31, 12, 66, 50, 29, 99, 86, 72, 45, 25, 10, 28, 19,  6, 90, 43, 29, 31, 67, 79, 46, 25, 74, 14, 97, 35, 76, 37, 65, 46, 23, 82,  6, 22, 30, 76, 93, 66, 94, 17, 96, 13, 20, 72},
        {63, 40, 78,  8, 52,  9, 90, 41, 70, 28, 36, 14, 46, 44, 85, 96, 24, 52, 58, 15, 87, 37,  5, 98, 99, 39, 13, 61, 76, 38, 44, 99, 83, 74, 90, 22, 53, 80, 56, 98, 30, 51, 63, 39, 44, 30, 91, 91,  4, 22, 27, 73, 17, 35, 53, 18, 35, 45, 54, 56, 27, 78, 48, 13, 69, 36, 44, 38, 71, 25, 30, 56, 15, 22, 73, 43, 32, 69, 59, 25, 93, 83, 45, 11, 34, 94, 44, 39, 92},
        {12, 36, 56, 88, 13, 96, 16, 12, 55, 54, 11, 47, 19, 78, 17, 17, 68, 81, 77, 51, 42, 55, 99, 85, 66, 27, 81, 79, 93, 42, 65, 61, 69, 74, 14,  1, 18, 56, 12,  1, 58, 37, 91, 22, 42, 66, 83, 25, 19,  4, 96, 41, 25, 45, 18, 69, 96, 88, 36, 93, 10, 12, 98, 32, 44, 83, 83,  4, 72, 91,  4, 27, 73,  7, 34, 37, 71, 60, 59, 31,  1, 54, 54, 44, 96, 93, 83, 36,  4, 45},
        {30, 18, 22, 20, 42, 96, 65, 79, 17, 41, 55, 69, 94, 81, 29, 80, 91, 31, 85, 25, 47, 26, 43, 49,  2, 99, 34, 67, 99, 76, 16, 14, 15, 93,  8, 32, 99, 44, 61, 77, 67, 50, 43, 55, 87, 55, 53, 72, 17, 46, 62, 25, 50, 99, 73,  5, 93, 48, 17, 31, 70, 80, 59,  9, 44, 59, 45, 13, 74, 66, 58, 94, 87, 73, 16, 14, 85, 38, 74, 99, 64, 23, 79, 28, 71, 42, 20, 37, 82, 31, 23},
        {51, 96, 39, 65, 46, 71, 56, 13, 29, 68, 53, 86, 45, 33, 51, 49, 12, 91, 21, 21, 76, 85,  2, 17, 98, 15, 46, 12, 60, 21, 88, 30, 92, 83, 44, 59, 42, 50, 27, 88, 46, 86, 94, 73, 45, 54, 23, 24, 14, 10, 94, 21, 20, 34, 23, 51,  4, 83, 99, 75, 90, 63, 60, 16, 22, 33, 83, 70, 11, 32, 10, 50, 29, 30, 83, 46, 11,  5, 31, 17, 86, 42, 49,  1, 44, 63, 28, 60,  7, 78, 95, 40},
        {44, 61, 89, 59,  4, 49, 51, 27, 69, 71, 46, 76, 44,  4,  9, 34, 56, 39, 15,  6, 94, 91, 75, 90, 65, 27, 56, 23, 74,  6, 23, 33, 36, 69, 14, 39,  5, 34, 35, 57, 33, 22, 76, 46, 56, 10, 61, 65, 98,  9, 16, 69,  4, 62, 65, 18, 99, 76, 49, 18, 72, 66, 73, 83, 82, 40, 76, 31, 89, 91, 27, 88, 17, 35, 41, 35, 32, 51, 32, 67, 52, 68, 74, 85, 80, 57,  7, 11, 62, 66, 47, 22, 67},
        {65, 37, 19, 97, 26, 17, 16, 24, 24, 17, 50, 37, 64, 82, 24, 36, 32, 11, 68, 34, 69, 31, 32, 89, 79, 93, 96, 68, 49, 90, 14, 23,  4,  4, 67, 99, 81, 74, 70, 74, 36, 96, 68,  9, 64, 39, 88, 35, 54, 89, 96, 58, 66, 27, 88, 97, 32, 14,  6, 35, 78, 20, 71,  6, 85, 66, 57,  2, 58, 91, 72,  5, 29, 56, 73, 48, 86, 52,  9, 93, 22, 57, 79, 42, 12,  1, 31, 68, 17, 59, 63, 76,  7, 77},
        {73, 81, 14, 13, 17, 20, 11,  9,  1, 83,  8, 85, 91, 70, 84, 63, 62, 77, 37,  7, 47,  1, 59, 95, 39, 69, 39, 21, 99,  9, 87,  2, 97, 16, 92, 36, 74, 71, 90, 66, 33, 73, 73, 75, 52, 91, 11, 12, 26, 53,  5, 26, 26, 48, 61, 50, 90, 65,  1, 87, 42, 47, 74, 35, 22, 73, 24, 26, 56, 70, 52,  5, 48, 41, 31, 18, 83, 27, 21, 39, 80, 85, 26,  8, 44,  2, 71,  7, 63, 22,  5, 52, 19,  8, 20},
        {17, 25, 21, 11, 72, 93, 33, 49, 64, 23, 53, 82,  3, 13, 91, 65, 85,  2, 40,  5, 42, 31, 77, 42,  5, 36,  6, 54,  4, 58,  7, 76, 87, 83, 25, 57, 66, 12, 74, 33, 85, 37, 74, 32, 20, 69,  3, 97, 91, 68, 82, 44, 19, 14, 89, 28, 85, 85, 80, 53, 34, 87, 58, 98, 88, 78, 48, 65, 98, 40, 11, 57, 10, 67, 70, 81, 60, 79, 74, 72, 97, 59, 79, 47, 30, 20, 54, 80, 89, 91, 14,  5, 33, 36, 79, 39},
        {60, 85, 59, 39, 60,  7, 57, 76, 77, 92,  6, 35, 15, 72, 23, 41, 45, 52, 95, 18, 64, 79, 86, 53, 56, 31, 69, 11, 91, 31, 84, 50, 44, 82, 22, 81, 41, 40, 30, 42, 30, 91, 48, 94, 74, 76, 64, 58, 74, 25, 96, 57, 14, 19,  3, 99, 28, 83, 15, 75, 99,  1, 89, 85, 79, 50,  3, 95, 32, 67, 44,  8,  7, 41, 62, 64, 29, 20, 14, 76, 26, 55, 48, 71, 69, 66, 19, 72, 44, 25, 14,  1, 48, 74, 12, 98,  7},
        {64, 66, 84, 24, 18, 16, 27, 48, 20, 14, 47, 69, 30, 86, 48, 40, 23, 16, 61, 21, 51, 50, 26, 47, 35, 33, 91, 28, 78, 64, 43, 68,  4, 79, 51,  8, 19, 60, 52, 95,  6, 68, 46, 86, 35, 97, 27, 58,  4, 65, 30, 58, 99, 12, 12, 75, 91, 39, 50, 31, 42, 64, 70,  4, 46,  7, 98, 73, 98, 93, 37, 89, 77, 91, 64, 71, 64, 65, 66, 21, 78, 62, 81, 74, 42, 20, 83, 70, 73, 95, 78, 45, 92, 27, 34, 53, 71, 15},
        {30, 11, 85, 31, 34, 71, 13, 48,  5, 14, 44,  3, 19, 67, 23, 73, 19, 57,  6, 90, 94, 72, 57, 69, 81, 62, 59, 68, 88, 57, 55, 69, 49, 13,  7, 87, 97, 80, 89,  5, 71,  5,  5, 26, 38, 40, 16, 62, 45, 99, 18, 38, 98, 24, 21, 26, 62, 74, 69,  4, 85, 57, 77, 35, 58, 67, 91, 79, 79, 57, 86, 28, 66, 34, 72, 51, 76, 78, 36, 95, 63, 90,  8, 78, 47, 63, 45, 31, 22, 70, 52, 48, 79, 94, 15, 77, 61, 67, 68},
        {23, 33, 44, 81, 80, 92, 93, 75, 94, 88, 23, 61, 39, 76, 22,  3, 28, 94, 32,  6, 49, 65, 41, 34, 18, 23,  8, 47, 62, 60,  3, 63, 33, 13, 80, 52, 31, 54, 73, 43, 70, 26, 16, 69, 57, 87, 83, 31,  3, 93, 70, 81, 47, 95, 77, 44, 29, 68, 39, 51, 56, 59, 63,  7, 25, 70,  7, 77, 43, 53, 64,  3, 94, 42, 95, 39, 18,  1, 66, 21, 16, 97, 20, 50, 90, 16, 70, 10, 95, 69, 29,  6, 25, 61, 41, 26, 15, 59, 63, 35}

    };

    unsigned long long MaxPathSum = 0;

    tuple<unsigned int, unsigned int> CurCoord(0, 0);
    PyramidNodes[0][0] = PyramidNode(NumberPyramid[0][0], CurCoord);

    for (int y = 1; y < kPyramidDepth; ++y) {
        for (int x = 0; x <= y; ++x) {
            get<0>(CurCoord) = x;
            get<1>(CurCoord) = y;
            PyramidNodes[y][x] = PyramidNode(NumberPyramid[y][x], CurCoord);
            if (x == 0 || PyramidNodes[y-1][x].NodeSum > PyramidNodes[y-1][x-1].NodeSum) {
                PyramidNodes[y][x].SetPrevMaxNode(&PyramidNodes[y-1][x]);
            }
            else if (x == y){
                PyramidNodes[y][x].SetPrevMaxNode(&PyramidNodes[y-1][x-1]);
            }
            else if (PyramidNodes[y-1][x].NodeSum > PyramidNodes[y-1][x-1].NodeSum){
                PyramidNodes[y][x].SetPrevMaxNode(&PyramidNodes[y-1][x]);
            }
            else {
                PyramidNodes[y][x].SetPrevMaxNode(&PyramidNodes[y-1][x-1]);
            }
            if (y == kPyramidDepth-1 && PyramidNodes[y][x].NodeSum > MaxPathSum) {
                MaxPathSum = PyramidNodes[y][x].NodeSum;
            }
        }
    }

    cout << "Max Path Sum: " << MaxPathSum << endl;
}