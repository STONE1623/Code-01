#include <iostream>

// 插入并保持数组有序，同时将最大值挤出
void insertAndShift(int arr[], int& size, int num) {
    int i;
    // 查找应该插入的位置
    for (i = 0; i < size && arr[i] < num; ++i) {
        // 什么都不做，只是遍历
    }
    // 将大于num的元素向后移动一位
    for (int j = size; j > i; --j) {
        arr[j] = arr[j - 1];
    }
    // 插入元素
    arr[i] = num;
    // 减少数组大小，因为最大值被挤出
    --size;
}

int main() {
    

    while(std::cout)
    {
        int a[] = {10, 12, 23, 25, 48, 48, 53, 58, 60, 78};
        int size = sizeof(a) / sizeof(a[0]); // 数组大小
        int num;
     //<< "请输入一个在数组最小值和最大值之间的数: ";
        std::cin >> num;

    // 检查输入的数是否在数组的最小值和最大值之间
    if (num < a[0] || num > a[size - 1]) {
        std::cout << "输入的数不在数组的最小值和最大值之间。" << std::endl;
        return 1;
    }

    // 插入数并保持数组有序，同时将最大值挤出
    insertAndShift(a, size, num);

    // 输出改变后的数组
    std::cout << "改变后的数组是: ";
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    }

    return 0;
}