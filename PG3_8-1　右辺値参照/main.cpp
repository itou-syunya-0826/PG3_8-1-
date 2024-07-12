#include <string>
#include <chrono>
#include <cstdio>
#include <thread> // 追加: std::this_thread::sleep_for

int main() {
    // 100000文字のstd::stringを初期化
    std::string a(100000, 'a');

    // コピー時間の計測
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a; // コピー
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // 移動時間の計測
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a); // 移動
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // 計測後にしばらく待つ
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 結果の表示
    std::printf("100,000文字を移動とコピーで比較しました。\n");
    std::printf("コピー: %lld μs\n", static_cast<long long>(copy_duration));
    std::printf("移動　: %lld μs\n", static_cast<long long>(move_duration));

    return 0;
}