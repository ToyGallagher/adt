#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> min_height(n + 1);
    min_height[0] = INT_MAX;
    int temp = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        temp = min(temp, height);
        min_height[i] = temp;
    }

    vector<int> rmin_height;
    for (auto it = min_height.rbegin(); it != min_height.rend(); ++it) {
        rmin_height.push_back(*it);
    }
    int value;
    for (int i = 0; i < q; i++) {
        int command;
        cin >> command;
        if (command == 1) {
            cin >> value;
            cout << min_height[value];
        } else if (command == 2) {
            cin >> value;
            if (value > min_height[0]) {
                cout << 0;
                continue;
            }
            auto low =
                lower_bound(rmin_height.begin(), rmin_height.end(), value);
            cout << n - distance(rmin_height.begin(), low);
        }
        cout << "\n";
    }

    return 0;
} 

/*
#include<bits/stdc++.h> 
using namespace std; 
int getInvCount(vector<long> arr, long long n) 
{ 
    long long invcount = 0; 
  
    for (long long i=1; i<n-1; i++) 
    { 
        
        long long small = 0; 
        for (long long j=i+1; j<n; j++) 
            if (arr[i] < arr[j]) 
                small++; 
  
       
        long long great = 0; 
        for (long long j=i-1; j>=0; j--) 
            if (arr[i]< arr[j]) 
                great++; 
  
        
        invcount += great*small; 
    } 
  
    return invcount; 
} 

int main()
{
    long long num,val;
    vector<long > arr ;
    cin >> num ;
    for(long long i = 0 ; i<num ; i++){
        cin >> val;
        arr.push_back(val);
    }
    long long n = sizeof(arr)/sizeof(arr[0]);
    cout <<getInvCount(arr, n);
    return 0;
}*/
คุณโชคดีมีโอกาสไปรับประทานอาหารที่
ร้านอาหารสุดหรู ร้านอาหารแห่งนี้จะเสิร์ฟอาหารเป็ นคอร์ส จำนวน
N คอร์สตามลำดับ (1 ⩽ N ⩽ 500,000) โดยแต่ละคอร์ส คุณสามารถเลือกขนาดของอาหารได้ โดยมีขนาด
ธรรมดา ขนาดพิเศษ และขนาดอภิมหาพิเศษ หรือจะเลือกข้ามอาหารคอร์สนั้นไปก็ได้ คุณรู้รายการอาหาร
ล่วงหน้ามาก่อนแล้ว และได้คำนวณไว้แล้วว่า อาหารคอร์สที่
i (สำหรับ 1 ⩽ i ⩽ N) หากเลือกขนาดธรรมดา
ขนาดพิเศษ และขนาดอภิมหาพิเศษ จะสร้างความพอใจให้คุณคิดเป็ น Xi
, Yi และ Zi คะแนนตามลำดับ
(โดยอาจไม่ได้เรียงจากน้อยไปมากก็ได้ เช่นอาหารบางอย่างรับประทานมากแล้วเลี่ยน) หากข้ามอาหารคอร์ส
ใดไป คะแนนความพอใจของคอร์สนั้นก็จะเป็ นศูนย์
การเลือกอาหารขนาดพิเศษคอร์สที่
i นั้น จะทำให้คุณรู้สึกอิ่มจนต้องข้ามอาหารคอร์สถัดไป (คือคอร์ส
ที่
i + 1) ส่วนการเลือกอาหารขนาดอภิมหาพิเศษคอร์สที่
i นั้น จะทำให้คุณรู้สึกอิ่มทั้
งตัวอิ่มทั้
งใจ จนต้อง
ข้ามอาหารสามคอร์สถัดไป (คือคอร์สที่
i + 1, i + 2 และ i + 3)
หมายเหตุ: การข้ามตามกฎนี้จะต้องข้ามเฉพาะคอร์สที่ 1 ถึง N ที่มีอยู่จริงเท่านั้น เช่น หากเลือก
อาหารขนาดอภิมหาพิเศษคอร์สที่ N − 2 ก็จะต้องข้ามอาหารคอร์สที่ N − 1 และ N ไป (คอร์สที่ N + 1
ไม่มี) หรือหากเลือกอาหารขนาดอภิมหาพิเศษคอร์สที่ N ก็ไม่ต้องข้ามอาหารคอร์สใดอีก
คุณต้องการหาว่าคะแนนความพอใจรวมสูงสุดที่
เป็ นไปได้เป็ นเท่าใด
ข้อมูลนำเข้า
บรรทัดแรก ระบุจำนวนเต็ม N (1 ⩽ N ⩽ 500,000) แทนจำนวนคอร์ส
อีก N บรรทัดถัดมา ระบุคะแนนความพอใจ กล่าวคือ บรรทัดที่ 1 + i สำหรับ 1 ⩽ i ⩽ N ระบุ
จำนวนเต็ม Xi
, Yi และ Zi คั่นด้วยช่องว่าง แทนคะแนนความพอใจของอาหารคอร์สที่
i ขนาดธรรมดา
ขนาดพิเศษ และขนาดอภิมหาพิเศษ ตามลำดับ (0 ⩽ Xi
, Yi
, Zi ⩽ 1,000,000,000)
มีข้อมูลทดสอบที่มีคะแนนรวม 20% ที่ N ⩽ 9
มีข้อมูลทดสอบที่มีคะแนนรวมอีก 30% ที่ N ⩽ 2,000
มีข้อมูลทดสอบที่มีคะแนนรวมอีก 50% ที่
ไม่มีเงื่อนไขเพิ่มเติมจากโจทย์
ข้อมูลส่งออก
มีหนึ่
งบรรทัด เป็ นจำนวนเต็มแทนคะแนนความพอใจรวมสูงสุดที่
เป็ นไปได้
คำตอบอาจมีค่ามาก ในการเขียนโปรแกรมจะต้องใช้ข้อมูลประเภท long long ในการเก็บคำตอบ

ตัวอย่าง
Input
9
14 44 81
25 32 47
21 45 30
46 38 39
12 20 64
10 19 24
24 26 31
10 33 44
21 34 39
Output
214