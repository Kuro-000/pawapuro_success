#!/usr/bin/env python
# _*_ coding: utf-8 _*_

import random

if __name__ == "__main__":
    with open('./loop.txt', mode='w') as f:
        f.write('1\n')  # ゲームスタート
        f.write('name\n')  # 名前を入力
        f.write('1\n')  # 背番号
        f.write('1\n')  # ポジション(1で投手、2から9で野手)
        f.write('\n'*4)  # 会話
        f.write('1\n')  # ステータス決定(天才・凡人・運動型・非運動型問わず)
        f.write('1\n')  # 初タイプ決定(力で勝負！)
        f.write('\n'*11) # 会話
        # for _ in range(31):
        #     f.write('1\n' + '\n'*3)  # 練習と結果
        
        randInteger = random.randint(1, 4)
        
        for i in range(31):
            # f.write(str((i % 4) + 1) + '\n' + '\n' * 10)
            # f.write(str(random.randint(1, 4)) + '\n' + '\n' * 10)
            f.write(str(((randInteger + i) % 4) + 1) + '\n' + '\n' * 10)
       
        """ for i in range(8):
            f.write(str((randInteger + 1 )% 4 + 1) + '\n' + '\n' * 10)
        for i in range(8):
            f.write(str((randInteger + 2 ) % 4 + 1) + '\n' + '\n' * 10)
        for i in range(8):
            f.write(str((randInteger + 3 ) % 4 + 1) + '\n' + '\n' * 10)
        for i in range(8):
            f.write(str((randInteger + 4 ) % 4 + 1) + '\n' + '\n' * 10)
        """