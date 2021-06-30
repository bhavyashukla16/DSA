// concatinate str1 and str1 n store it in a temp string
// if str2 is a substring of temp, it is a rotation else not

bool areRotations( string str1, string str2) {

    if (str1.length()!=str2.length())
    return false;

    string temp = str1 + str1;

    return ( temp.find(str2) != string::npos ); // return true when they r rotations

}