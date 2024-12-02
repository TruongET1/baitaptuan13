#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Cấu trúc giỏ hàng (node trong hàng đợi)
struct Cart {
    string customerName;        // Tên khách hàng
    int productA_quantity;      // Số lượng sản phẩm A
    int productB_quantity;      // Số lượng sản phẩm B
    double productA_price;      // Giá sản phẩm A
    double productB_price;      // Giá sản phẩm B

    // Hàm tính tổng tiền giỏ hàng
    double getTotalPrice() const {
        return productA_quantity * productA_price + productB_quantity * productB_price;
    }
};

int main() {
    queue<Cart> checkoutQueue; // Hàng đợi chứa các giỏ hàng
    double totalRevenue = 0;   // Tổng số tiền thu được
    int totalProductASold = 0; // Tổng số lượng sản phẩm A đã bán

    // Thêm giỏ hàng vào hàng đợi
    checkoutQueue.push({ "Alice", 3, 2, 10.0, 15.0 });
    checkoutQueue.push({ "Bob", 1, 1, 10.0, 15.0 });
    checkoutQueue.push({ "Charlie", 4, 0, 10.0, 15.0 });

    // Xử lý thanh toán từng khách hàng
    while (!checkoutQueue.empty()) {
        Cart currentCart = checkoutQueue.front();
        checkoutQueue.pop();

        // Cập nhật tổng số tiền thu được
        double cartTotal = currentCart.getTotalPrice();
        totalRevenue += cartTotal;

        // Cập nhật số lượng sản phẩm A đã bán
        totalProductASold += currentCart.productA_quantity;

        // Hiển thị thông tin thanh toán của khách hàng
        cout << "Customer: " << currentCart.customerName << endl;
        cout << "Total Amount: $" << cartTotal << endl;
        cout << "--------------------------" << endl;
    }

    // Hiển thị tổng kết sau phiên làm việc
    cout << "Total Revenue: $" << totalRevenue << endl;
    cout << "Total Product A Sold: " << totalProductASold << " units" << endl;

    return 0;
}
