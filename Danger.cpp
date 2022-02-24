#include <string.h>
#include <stdio.h>
#include <termios.h> 
#include <unistd.h>
#include <iostream>
using namespace std;
int clear_icanon(void)
{
  struct termios settings;
  int result;
  result = tcgetattr (STDIN_FILENO, &settings);
  if (result < 0)
    {
      perror ("error in tcgetattr");
      return 0;
    }

  settings.c_lflag &= ~ICANON;

  result = tcsetattr (STDIN_FILENO, TCSANOW, &settings);
  if (result < 0)
    {
      perror ("error in tcsetattr");
      return 0;
   }
  return 1;
}


int main()
{
    clear_icanon(); // Changes terminal from canonical mode to non canonical mode.
    int t,a[10],m=-1;string S,F="";
    cin>>t>>S;
    for(int i=0;i<10;i++)cin>>a[i];
    for(auto x:S){
            if(m==-1 && a[x-'1']>x-'0'){
                m=x-'1';
                F.append(a[m]);
        }
        else if(x-'1'==m)F.append(a[m]);
        else F.append(x);
}
cout<<F;
}