# Checkout-System

## 分三個使用者，分別有各自的UI

### User Interface
 - 宣告大多數 UI 會用到的功能，如：input、status等等。

### CashierUI 
 - 可以選購貨物，並輸出發票(Reciept)。

### SupplierUI 
 - 可以把東西運進倉庫，進貨前會有表單確認。

### ManagerUI 
 - 可以監測貨物的流向。
  
### Main System
 - 可以根據不同的請求，處理前端需要的不同的資料。
 - Search：使用File Connector 只會傳 2D 的 std::vector 回來而已，在System裡面就要將它轉成 Object，如：Good、Actvity。
 - Confirm：使用 File Connector 來實作進貨、販賣、紀錄活動。

### File Connector
 - 直接把 csv 檔案當成 Database 來用。
 - 插入資料到 Database。
 - 拿出 Database 資料。
 - 可以獨立運作並不只能配合這個系統。
