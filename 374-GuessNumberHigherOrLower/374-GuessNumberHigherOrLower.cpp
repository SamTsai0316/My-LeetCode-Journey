// Last updated: 2026/4/11 下午7:20:08
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

/*運用guess的回傳值了解當前的數字是大於還是小於，如果每次都用++--會花太多時間，所以每次取中間值*/
class Solution 
{
public:
    int guessNumber(int n) 
    {
        int left = 1;
        int right = n;

        while(left<=right)   // n=1 and pick=1 時如果 left<right 會回傳 -1 所以要小於等於
        {
            int mid =  left+(right-left)/2;     // 如果用 (right+left)/2; right+left 可能會太大而 int 無法表示 
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==1) // pick 比當前 left+right 的一半還要大，所以 left = mid+1
                left = mid+1;
            else
                right = mid-1;

        }
        return -1 ;    //跳出來代表找不到 
    }
};