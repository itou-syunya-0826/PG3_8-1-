#include <string>
#include <chrono>
#include <cstdio>
#include <thread> // �ǉ�: std::this_thread::sleep_for

int main() {
    // 100000������std::string��������
    std::string a(100000, 'a');

    // �R�s�[���Ԃ̌v��
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a; // �R�s�[
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // �ړ����Ԃ̌v��
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a); // �ړ�
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // �v����ɂ��΂炭�҂�
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // ���ʂ̕\��
    std::printf("100,000�������ړ��ƃR�s�[�Ŕ�r���܂����B\n");
    std::printf("�R�s�[: %lld ��s\n", static_cast<long long>(copy_duration));
    std::printf("�ړ��@: %lld ��s\n", static_cast<long long>(move_duration));

    return 0;
}