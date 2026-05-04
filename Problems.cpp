#include <iostream>
#include "Problems.h"
#include "Helpers.h"
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

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