#include <iostream >

using namespace std;
// tao mang nhieu chieu 
void taomang(int **&arr, int r, int c)
{
	srand(time(NULL));
	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[c];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
		    arr[i][j] = rand() % 50  + 1;
		}
	}

}
// xuat mang 
void xuat_mang(int**& arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << "   "<< arr[i][j] << " ";
		}
		cout << endl;
	}
}
// tim so nho nhat trong cot 
int * check_so_nho_nhat(int **&arr, int idx , int c  )
{
	int min = arr[idx-1][0];
	for (int i = 0 ; i < c; i++)
	{
		if (arr[idx -1][i] < min)
		{
			min = arr[idx-1][i];
		}
	}
	return &min;
}
// tinh tong cac phan tu tren cot 
int tinh_tong(int**& arr, int cot ,int r , int tong =0,int idx =0 )
{
	if (idx == r)
	{
		return tong;
	}
	tong += arr[idx][cot];
	return tinh_tong(arr, cot, r, tong, idx + 1);

}
void  flatmap(int**& arr, int cot, int r)
{
	for (int i = 0; i < r; i++)
	{
		cout << arr[i][cot - 1] << " ";
	}

}
bool isnguyen_to(int x)
{
	if (x == 2)
	{
		return false ;
	}
	for (int i = 2; i <= x / 2; i++)
	{
		if (x% i == 0 )
		{
			return false ;
		}
		return true;

	}
}
void   xuat_so_nguyen_to(int**& arr, int r, int c, char ten)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (isnguyen_to(arr[i][j]) == true && ten== 'a')
			{
				cout << arr[i][j] << " ";
			}
			if (isnguyen_to(arr[i][j]) == true&& ten=='l')
			{
				cout << arr[i][j] << " -" << " dong " << i << " ,cot " << j << endl;
			}
		}
	}
}
//void  xuat_so_nguyen_to_theo_Lan(int**& arr, int r, int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			if (isnguyen_to(arr[i][j]) == true)
//			{
//				cout << arr[i][j] << " -" << " dong " << i << " ,cot " << j << endl;
//			}
//		}
//	}
//}
bool lap() 
{
	char response;
	std::cout << "Ban co muon xem them kieu con lai (y/n): ";
	std::cin >> response;

	// Kiểm tra nếu người dùng muốn xem tiếp
	return (response == 'y' || response == 'Y');
}
int main()
{
	// bai so 1 
	cout << "Bai 1: " << endl;
	int c, r, idx, cot, chuyen_vi;
	char  key;
	std::cout << "Moi ban nhap vao so dong:";
	std::cin >> r;
	std::cout << "Moi ban nhap vao so cot :";
	std::cin >> c;
	// tao con tro cap 2 quan li cac mang nho 
	int** arr = new int *[r];
	cout << "Mang vua duoc tao la: " << endl; 
	// goi ham tao mang de tao mang c*r 
	taomang(arr, r, c);
	// xuat mang vua tao ra 
	xuat_mang(arr, r, c);
	// bai 2 
	cout << "Bai 2: " <<  endl; 
	cout << "Moi ban nhap so dong can tim min: ";
	cin >> idx;
	cout << "Gia tri so nho nhat dong " << idx << " la: ";
	// xuat gia tri nho nhat ra truoc de de hinh dung 
	cout << *check_so_nho_nhat(arr, idx, c) << endl;
	cout << "Dia chi so nho nhat dong " << idx << " la: ";
	cout << check_so_nho_nhat(arr, idx, c) << endl;
	// bai 3 
	cout << "Bai 3 " << endl;
	cout << "Moi ban nhap vao cot muon tinh tong:  ";
	cin >> cot;
	cout << "Tong cac phan tu tren cot "<< cot << "la : ";
	cout << tinh_tong(arr, cot - 1, r) << endl;
	// bai 4 
	cout << "Bai 4 " << endl;
	cout << "Nhap cot ma ban muon chuyen thanh hang" << endl;
	cin >> chuyen_vi;
	cout << "Mang 1 chieu duoc chuyen tu cot " << chuyen_vi << " la : " << endl; 
	flatmap(arr, chuyen_vi, r);
	// bai 5 
	
	cout << "Bai 5 " << endl;
	keyword :
	cout << "Ban muon xuat so nguyen to theo kieu An hay Lan (A/L)";
	cin >> key;
	if (key == 'A'||key =='a')
	{
		xuat_so_nguyen_to(arr, r, c,'a'); cout << endl;
	}
	if (key == 'L'||key =='l')
	{
		xuat_so_nguyen_to(arr, r, c,'l'); cout << endl;
	}
	while (lap()) 
	{
		goto keyword ;
	}
	/*delete arr;*/
	return 1;
}