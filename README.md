# JUMP JUMP
Họ và tên : Lê Duy Đông\
MSSV : 23020044\
Lớp : K68-CC\
Lớp học phần : INT-2215 50 23_24\
Link bài tập lớn : [BTL](https://github.com/Tension08/jump-jump)
# Demo Game :
Đây là đường dẫn drive tới [video demo](https://drive.google.com/file/d/193pvNUyWElpJxYIAbbhAeGARYIrNZL_j/view?usp=sharing)
# Giới thiệu game 
Game Jump Jump là thể loại game endless run, chạy, vượt qua chướng ngại vật để có thể đạt được số điểm cao nhất.
- [0.Cách tải game](#0-cách-tải-game)
   * [a. Bao gồm code](#a-bao-gồm-code)
   * [b. Không bao gồm code](#b-không-bao-gồm-code)
- [1.Mô tả game](#1-mô-tả-game)
  * [1.1 Bắt đầu game](#1-1-bắt-đầu-game)
  * [1.2 Bắt đầu chơi](#1-2-bắt-đầu-chơi)
  * [1.3 Nhân vật :](#1-3-Nhân-vật)
  * [1.4 Cách chơi :](#1-4-cách-chơi)
  * [1.5 Kẻ thù](#1-5-kẻ-thù)
- [2.Nguồn tham khảo](#2-nguồn-tham-khảo)
- [3.Các kiến thức được dùng](#3-các-kiến-thức-được-dùng)
- [4.Hướng phát triển](#4-hướng-phát-triển)
## 0.Cách tải game
### a. Bao gồm code
* B1: Bạn cần tải một ide để chạy có thể vscode([Link](https://code.visualstudio.com/download)) hoặc Visual studio (tham khảo cách tải và setup sdl từ [lazyfoo](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php)) hoặc xcode ([lazyfoo](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/xcode/index.php))
* B2: Clone code về máy : gõ lệnh ``` $ git clone https://github.com/Tension08/jump-jump.git```
* B3: Tùy vào từng ide :
  * Nếu bạn dùng Vscode : bạn cần tải thêm terminal hoặc mingw về để dử dụng, sau đó chỉ cần gõ `$make` và `$./build/debug/play`.
  * Nếu dùng Visual Studio : chạy bình thường lưu ý cần thêm các file .dll có sẵn
  * Nếu dùng Xcode : Bạn cần thêm các file .framework có sẵn trong code vào phẩn general trong project củ mình trước khi build.
### b. Không bao gồm code
## 1.Mô tả game
### 1.1 Bắt đầu game 
* Nhấn vào nút "play" để bắt đầu trò chơi:
![menu image](/value/menu.png)
* Tuy nhiên trước khi bắt đầu người chơi nên nhấn vào phần 'settings' để chọn nhân vật :
![settings](/value/choose.png)
* Ngoài ra có thể nhấn vào biểu tượng dấu "?" để đọc hướng dẫn trò chơi:
![information](/value/information.png)
### 1.2 Bắt đầu chơi
Hình ảnh minh họa :
![review game](/value/review.png)

### 1.3 Nhân vật :
Để chọn hiệp sĩ nhấn phím '1' còn pháp sư nhấn phím '2':
* ![musketer](/value/char.png) : hiệp sĩ nhiều máu hơn nhưng không thể tấn công tầm xa, chỉ có thể chạy và nhảy.
* ![enchan](/value/char1.png) : pháp sư ít máu hơn hiệp sĩ nhưng tấn công xa được bằng đạn ma pháp ![magic](/value/magic.png)

### 1.4 Cách chơi :
* Nhấn phím : ![up](/value/up.png) để nhảy.
* Nhấn chuột trái :![mouseleft](/value/mouseleft.png) để tấn công nếu chọn pháp sư.

### 1.5 Kẻ thù

* ![dude](/value/Dude.png) : đứng yên, cần phải vượt qua. 
* ![owlet](/value/Owlet.png) : liên tục lùi về sau, ném đá về phía người chơi.
* ![rock](/value/bullet.png) : đạn được owlet monster dùng.

### 1.6 Thao tác trong game

1. Ấn vào nút "pause" ở góc phải màn hình để tạm dừng trò chơi.
2. Sau khi tạm dừng màn hình này sẽ hiện ra :\
![pause](/value/afterpause.png)
3. Nhấn nút "back" nếu muốn tiếp tục chơi hoặc nút "menu" nếu muốn quay trở lại màn hình ban đầu

### 1.7 Thua
1. Bạn sẽ mất máu nếu chạm vào quái vật hoặc đạn
2. Khi thanh máu hết bạn sẽ thua và trò chơi kết thúc:\  ![lose](/value/died.png)
3. Bạn sẽ có 4 máu nếu chọn hiệp sĩ và 2 máu nếu chọn pháp sư.
!(HP)[/value/HP.png]

## 2. Nguồn tham khảo
* Hình ảnh lấy từ các nguồn trên google, có thể lấy từ [craftpix](https://craftpix.net/) các hình ảnh động của nhân vật và kẻ thù, ở đây cũng được đề xuất các phông chữ phù hợp với game của bạn, ngoài ra có thể tự thiết kế từ [pixilart](https://www.pixilart.com/)
* Học thêm và tham khảo từ [phattrienphanmem123 a-z]( https://www.youtube.com/watch?v=q1WzniyeGTU&list=PLR7NDiX0QsfTIEQUeYCfc2MyCquX0ig9V).
* Tham khảo cả từ [lazyfoo](https://lazyfoo.net/tutorials/SDL).

## 3. Các kiến thức được dùng
- Trong file `CommonFunc.h` và `CommonFunc.cpp` :
  * Khai báo thư viện cơ bản cũng như lớp class cơ bản của trò chơi là `BaseObject()` có chức năng xử lý các hình ảnh và các vật thể `object`
  * Ngoài ra còn có struct map() là dữ liệu bản đồ, và struct input dùng xử lý các sự kiện đầu vào.
  * Lớp SDLCommonFunc sẽ giúp xử lý các sự kiện cần cho chức năng của game.
- Trong file `Map.h` và `Map.cpp` :
  * Hai file này dùng để xử lý map bằng cách lấy dữ liệu từ file map.txt có sẵn rồi render lên màn hình các vị trí tương ứng
  * Tuy nhiên, do logic game là scrolling background nên việc render các phần của bản đồ LoadTiles là không cần thiết nên hai file này chỉ dùng để tạo chỗ đứng cho nhân vật và kẻ thù.
- File `MainObject.h` và `MainObject.cpp` :
  * Dùng để xử lý nhân vật game với việc lưu các hình ảnh nhân vật từ file để có animation : set_clips() và Show()
  * Hàm CheckToMap() là file xử lý va chạm của nhân vật với bản đồ
  * Hàm DoPlayer() giúp xử lý việc di chuyển của nhân vật bằng cách cập nhật các giá trị x_val và y_val của nhân vật.
  * Hàm HandleInputAction() giúp xử lý các thao tác của người chơi với nhân vật, và sự kiện chuột tạo ra đạn tấn công cho nhân vật.
  * Đối với nhân vật tấn công tầm xa cần có thêm các hàm tọa danh sách đạn set_bullet_list(), xử lý đạn HandleBullet, xóa đạn Removevullet();
- File `bullet.h` và `bullet.cpp` :
  * Đưa ra loại đạn BulletType() với Rock cho kẻ địch còn Magic co nhân vật game và xét hướng bắt BulletDir() cho các đối tượng được chỉ định.
  * Đây là hàm cơ bản, chỉ cần phần isMove biến thành true thì sẽ render ra đạn với hướng bay được chỉ định, x_val và y_val sẽ quyết định tốc độ của đạn.
- File `ThreatsObject.h` và `ThreatsObject.cpp` : Đây là file xử lý kẻ địch mà ta tạo ra, đa phần giống với phần MainObject(), chỉ khác là mọi chuyển động sẽ là tự động
  * Các hàm như set_clips(), LoadImg(), Show() khá giống với khi xử ký nhân vật game, ngoài ra còn có các hàm tạo đạn
  * Các loại kẻ thù ở đây gồm hai loại chính : Static và Attack.
      * Đối với static : ta cần cho kẻ địch này di chuyển cùng với background -> tạo nên cảm giác kẻ địch đang đứng yên còn nhân vật đang chạy về phía nó
      * Đối với attack : kẻ địch này sẽ có hoạt ảnh chuyển động chạy sang phải và có hàm tạo đạn cho nó giúp nó tấn công người chơi, kẻ địch này gần giống kiểu boss trong game
- File `showBar.h` và `showBar.cpp`: Dùng render thanh máu theo trạng thái của người chơi
- File `ImpTimer.h` và `ImpTimer.cpp` : (Code lấy phần lớn từ nguồn tham khảo lazyfoo)
  * start(): Bắt đầu đo thời gian bằng cách lưu giá trị của SDL_GetTicks() vào start_tick_.
  * stop(): Dừng đo thời gian bằng cách đặt is_started_ và is_paused_ thành false.
  * paused(): Tạm dừng đo thời gian. Nếu đã bắt đầu và chưa được tạm dừng trước đó, thì lưu thời điểm hiện tại và tính toán thời gian đã trôi qua kể từ khi bắt đầu.
  * unpaused(): Khôi phục việc đo thời gian sau khi đã tạm dừng. Nếu đã được tạm dừng trước đó, thì tính lại start_tick_ dựa trên thời gian tạm dừng và thời gian hiện tại.
  * Ở đây mình chỉ dùng nó để làm cho game mượt mà hơn.
- File `TextObject.h` và `TextObject.cpp` :
  * Phần này để render chung cho các text lên màn hình nhờ LoadFromRenderText() và RenderText().
  * Có thể set màu cho văn bản bằng SetColor() và nhập vào các giá trị r,g,b khác nhau để xét màu, trong file này cũng để sẵn 3 màu cơ bản là BLACK, WHITE, RED
- Phần `bonnusCommon.cpp` :
  * CheckCollosion() : là hàm đơn giản trong việc xét va chạm giữa 2 objects với nhau
  * afterpause() : là hàm xử lý sự kiện chuột sau khi tạm dừng màn hình khi đang trong trò chơi, hàm này sẽ tải lên một ảnh nền ban đầu, và render ra 2 nút bấm và chờ xử lý các sự kiện.
  * choose() : là một hàm nếu như ấn settings khi vào màn hình menu thì sẽ hiện ra, hàm này tai lên màn hình chọn nhân vật và chờ xử lý sự kiện bàn phím.
  * showInformation() : gần giống với hàm choose nhưng là màn hình hướng dẫn.
- Phần `menu.cpp` :
* Là hàm sự kiện ban đầu của game, tải lên hình ảnh ban đầu cùng các nút bấm
* Chờ sự kiện chuột và trả về các số tương ứng để chương trình xử lý
- Phần `main.cpp` :
  * đây là phần chính cho logic  và gameloop.
  * Ban đầu sẽ khởi tạo background, menu, các button cơ bản , kế đến khởi taọ 2 loại kẻ thù với MakeThreadList1 và MakeThreadList2, tiếp theo là khởi tạo biến năng lượng player_power cho nhân vật và cả biến tính điểm mark_game.
  * Bắt đầu vòng lặp với biến menuN, tạo ra các kẻ thù ngay từ bước này cho trò chơi,  khi thỏa mãn điều kiện thì tạo menu và đưa lên màn hình, xử lý các sự kiện và bắt đầu chạy game khi biến run = true.
  * Trong vòng lặp xử lý các sự kiện nhân vật và kẻ thù cũng như xét các va chạm giữa người chơi và kẻ thù bCol1, giữa người chơi và đạn bCol2, và tCol giữa đạn của người chơi và kẻ địch.
  * mark_game sẽ luôn tục cập nhật khoảng cách di chuyển của người chơi.
  * biến check máu final_check sẽ là biến dùng để kết thúc trò chơi, khi final_check vượt qua một lượng nhất định thì thông báo kết thúc game over hiện ra và run = false, có 3s delay trước khi trở về màn hình menu và tiếp tục vòng lặp với menuN
  * Kết thúc game , giải phóng toàn bộ bộ nhớ
## 4. Hướng phát triển :
* Tự nhận xét chung :
  * game đang còn đơn giản, nhân vật chỉ có trạng thái chuyển động cơ bản chưa có nhiều hành động khác nhau.
  * Game chưa đúng với một tựa game endless run, logic game chỉ là cho nhân vật chuyển động tại chỗ sau đó cho background và các enemy di chuyển -> việc này gây ra nhiều hạn chế như sẽ khó tạo ra các chướng ngại như gò đất hay hố
  * Chưa có các items vật phẩm trong khi chơi game
* Hướng phát triển tự đưa ra:
  * Cập nhật thêm các hành động như trượt, đau, chết, ...
  * Thiết kế game theo kiểu tạo ra thư viện segments, sau đó nối lại một cách ngẫu nhiên để tạo ra một map dài vô tận
  * Thiết kế items và cửa hàng, cappj nhật thêm nhân vật và kỹ năng
# Kết luận
* Qua việc làm BTL, đã giúp mình hiểu hơn về cách lập trình hướng đối tương, cách chia nhỏ chương trình.
* Đã biết cơ bản cách dùng class và sdl
* Hạn chế :
  * `main.cpp` còn quá dài, vẫn chưa chia nhỏ file một cách triệt để
  * sử dụng class còn nhiều hạn chế
  * chưa dùng được sdl_mixer
