#include <iostream>
#include <cmath>
#include <algorithm> // เพิ่มเฮดไฟล์ algorithm
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool[][M], int, int, int);
void showImage(const bool[][M]);

int main()
{
    bool image[N][M] = {}; // แผ่นภาพเริ่มต้นทุกจุดเป็น 0
    int s, x, y;
    do
    {
        showImage(image); // แสดงผลแผ่นภาพ
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;          // รับค่าพู่กัน
        updateImage(image, s, x, y); // อัปเดตแผ่นภาพ
    } while (s != 0 || x != 0 || y != 0); // ออกจากโปรแกรมเมื่อป้อน 0 0 0

    return 0;
}

// ฟังก์ชันแสดงแผ่นภาพ
void showImage(const bool image[N][M])
{
    // ขอบด้านบน
    for (int i = 0; i < M + 2; ++i)
    {
        cout << "-";
    }
    cout << endl;

    // แสดงภาพภายในกรอบ
    for (int i = 0; i < N; ++i)
    {
        cout << "|"; // ขอบซ้าย
        for (int j = 0; j < M; ++j)
        {
            if (image[i][j])
            {
                cout << "*"; // ถ้ามีค่าเป็น 1, แสดง *
            }
            else
            {
                cout << " "; // ถ้ามีค่าเป็น 0, แสดงช่องว่าง
            }
        }
        cout << "|"; // ขอบขวา
        cout << endl;
    }

    // ขอบด้านล่าง
    for (int i = 0; i < M + 2; ++i)
    {
        cout << "-";
    }
    cout << endl;
}

// ฟังก์ชันอัปเดตแผ่นภาพตามตำแหน่งและขนาดของพู่กัน
void updateImage(bool image[][M], int s, int x, int y)
{
    // ตรวจสอบตำแหน่งที่พู่กันสามารถไปได้ในรัศมี
    for (int i = max(0, x - (s - 1)); i < min(N, x + (s - 1) + 1); ++i)
    {
        for (int j = max(0, y - (s - 1)); j < min(M, y + (s - 1) + 1); ++j)
        {
            // ใช้สมการวงกลม (Pythagorean theorem) เพื่อตรวจสอบว่าจุดนี้อยู่ในรัศมีของพู่กัน
            if (sqrt(pow(i - x, 2) + pow(j - y, 2)) <= (s - 1))
            {
                image[i][j] = 1; // อัปเดตเป็น 1 (จุดที่วาด)
            }
        }
    }
}