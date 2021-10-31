#include <iostream>
#include <string>
using namespace std;

class cube{
    public:
        cube(){
            for(int i=0; i <= 6; i++){
                for(int j=0; j <= 9; j++){
                    pos[i*9+j] = colors[i];
                }
            }
        }
        char get(int n){
            return pos[n];
        }
        void move(string move){
            
        }
        void print(){
            //blue
            cout << "      " << pos[33] << " " << pos[34] << " " << pos[35] << "\n";
            cout << "      " << pos[30] << " " << pos[31] << " " << pos[32] << "\n";
            cout << "      " << pos[27] << " " << pos[28] << " " << pos[29] << "\n";

            //orange
            cout << pos[36] << " " << pos[39] << " " << pos[42] << " ";
            //white
            cout << pos[0] << " " << pos[1] << " " << pos[2] << " ";
            //red
            cout << pos[20] << " " << pos[23] << " " << pos[26] << " ";
            //yellow
            cout << pos[51] << " " << pos[52] << " " << pos[53] << " " << "\n";

            //orange
            cout << pos[37] << " " << pos[40] << " " << pos[43] << " ";
            //white
            cout << pos[3] << " " << pos[4] << " " << pos[6] << " ";
            //red
            cout << pos[19] << " " << pos[22] << " " << pos[25] << " ";
            //yellow
            cout << pos[48] << " " << pos[49] << " " << pos[50] << " " << "\n";

            //orange
            cout << pos[38] << " " << pos[41] << " " << pos[44] << " ";
            //white
            cout << pos[6] << " " << pos[7] << " " << pos[8] << " ";
            //red
            cout << pos[18] << " " << pos[21] << " " << pos[24] << " ";
            //yellow
            cout << pos[45] << " " << pos[46] << " " << pos[47] << " " << "\n";

            //green
            cout << "      " << pos[9] << " " << pos[10] << " " << pos[11] << "\n";
            cout << "      " << pos[12] << " " << pos[13] << " " << pos[14] << "\n";
            cout << "      " << pos[15] << " " << pos[16] << " " << pos[17] << "\n";
        }
    private:
        char pos[54];
        char colors[6] = {'w', 'g', 'r', 'b', 'o', 'y'};
        /*char pos[54] = {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w',
                        'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 
                        'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r',
                        'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                        'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 
                        'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y'};*/

        int color_to_int(char color){
            if(color == 'w'){
                return 0;
            }
            if(color == 'g'){
                return 1;
            }
            if(color == 'r'){
                return 2;
            }
            if(color == 'b'){
                return 3;
            }
            if(color == 'o'){
                return 4;
            }
            if(color == 'y'){
                return 5;
            }
        }

        void turn_face(int direction, int color_num){
            int mod = color_num*9;
            int n1, n2;

            if(direction == 0){
                n1 = 6;
                n2 = 2;
            }
            else{
                n1 = 2;
                n2 = 6;
            }

            char temp[2] = {pos[mod], pos[mod+8]};
            pos[mod] = pos[mod+n1];
            pos[mod+8] = pos[mod+n2];
            pos[mod+n2] = temp[0];
            pos[mod+n1] = temp[1];

            if(direction == 0){
                n1 = 3;
                n2 = 5;
            }
            else{
                n1 = 5;
                n2 = 3;
            }

            temp[0] = pos[mod+1];
            temp[1] = pos[mod+7];
            pos[mod+1] = pos[mod+n1];
            pos[mod+7] = pos[mod+n2];
            pos[mod+n2] = temp[0];
            pos[mod+n1] = temp[1];
        }

        void clock_turn_side(char color){
            int color_num = color_to_int(color); 
            if(color == 'w'){
                int side[12] = {9, 10, 11, 18, 19, 20, 27, 28, 29, 36, 37, 38};
            }
            else if(color == 'g'){
                int side[12] = {6, 7, 8, 18, 21, 24, 47, 46, 45, 38, 41, 44};
            }
            else if(color == 'r'){
                int side[12] = {8, 5, 2, 27, 30, 33, 47, 50, 53, 11, 14, 17};
            }
            else if(color == 'b'){
                int side[12] = {};
            }
            else if(color == 'o'){
                int side[12] = {};
            }
            else if(color == 'y'){
                int side[12] = {};
            }
        }
};


int main(){
    cube c;
    c.print();
    return 0;
}