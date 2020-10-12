/*[Pawapuro.cc]
Author : Tojio Hirakubo
First date : 2017/01/10

「舞台は高校3年甲子園予選大会1ヶ月前。主人公はラストスパートをかけてチームを甲子園に導くことはできるのだろうか。」

練習期間1ヶ月(31日)
能力について
・投手はスライダー、カーブ、フォーク、シンカー、シュートの変化球を習得可能とする。基本能力は球速、コントロール、スタミナとする。
・野手は弾道、ミート、パワー、走力、肩力、守備力、補給とする。
・各変化球のMax値を7とし、球速のMax値を165km/h、その他はG~Sとする。
・基本能力の上昇の際に必要な能力ポイントは以下とする。
[球速] : ???
[コントロール] : F {20}、E {40}、D {50}、C {60}、B {70}、A {80}、S {90}
[スタミナ] : F {20}、E {40}、D {50}、C {60}、B {70}、A {80}、S {90}
[変化球] : 1 {1}、2 {2}、3 {3}、4 {4}、5 {5}、6 {6}、7 {7}
[弾道] : 2 {2}、3 {3}、4 {4}
[ミート] : F {20}、E {40}、D {50}、C {60}、B {70}、A {80}、S {90}
[パワー] : F {20}、E {40}、D {50}、C {60}、B {70}、A {80}、S {90}
[走力] : F {20}、E {40}、D {50}、C {60}、B {70}、A {80}、S {90}
[肩力] : F {20}、E {40}、D {50}、C {60}、B {70}、A {80}、S {90}
[守備力] : F {20}、E {40}、D {50}、C {60}、B {70}、A {80}、S {90}
[補給] : F {20}、E {40}、D {50}、C {60}、B {70}、A {80}、S {90}
・調子の幅は、絶不調、不調、普通、好調、絶好調の5段階とする
*/

#include "./conio.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
// #include "character.cc"
// #include "practice.cpp"

#define DAYS 31 // 練習日数
// Lv.1時の練習メニューで得られるポイント
#define BALL_POINT 5
#define CONTROL_POINT 5
#define STAMINA_POINT 5
#define EVOLVING_POINT 5
#define MEET_POINT 5
#define POWER_POINT 5
#define RUN_POINT 5
#define SHOLDER_POINT 5
#define PROTECT_POINT 5
#define CATCHING_POINT 5

// クソ面倒ですが各練習を定義
// 使う分だけ上から追加していきます
// 絶対後からクラス対応する

// ball練習
// muscle, technique, spirit
int BALL1[3] = {10, 4, 2};
int BALL2[3] = {13, 8, 4};
int BALL3[3] = {17, 12, 8};

// contro練習
// technique, spirit
int CONTROL1[2] = {10, 6};
int CONTROL2[2] = {13, 10};
int CONTROL3[2] = {17, 12};

// stamina練習
// muscle, spirit, stamina, stamina
int STAMINA1[4] = {8, 3, 1, 6};
int STAMINA2[4] = {11, 5, 1, 6};
int STAMINA3[4] = {14, 8, 1, 6};

// evolvinれ練習
// evolving, technique, spirit
int EVOLVING1[3] = {3, 10, 3};
int EVOLVING2[3] = {6, 13, 6};
int EVOLVING3[3] = {10, 17, 10};

// #define GENIUS_DENOMINATOR 25 // 天才型出現判定の分母
#define GENIUS_DENOMINATOR 9999999999 // 天才型出現判定の分母
#define DAIJYOUBU_1 1 // ダイジョーブ博士出現率(rand()%10<DAIJYOUBU_1)
#define DAIJYOUBU_2 1 // ダイジョーブ博士成功率(rand()%10<DAIJYOUBU_2)
#define INTERLEAVE_PROPORTION 0.05 // インターリーブ学習の割合、MAXは1.5

#define HP 100 // 体力をとりあえず100と設定
#define LEVEL1_PRACTICE_HP 15
#define LEVEL2_PRACTICE_HP 20
#define LEVEL3_PRACTICE_HP 30

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::istream;
using std::ofstream;
using std::right;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;

void Control_color(char);
void Stamina_color(char);
void Trajectory_color(char);
void Meet_color(char);
void Power_color(char);
void Run_color(char);
void Sholder_color(char);
void Protect_color(char);
void Catching_color(char);

void Slider_1(int);
void Slider_2(int);
void Slider_3(int);
void Slider_4(int);
void Slider_5(int);
void Slider_6(int);
void Slider_7(int);

void Curve_1(int);
void Curve_2(int);
void Curve_3(int);
void Curve_4(int);
void Curve_5(int);
void Curve_6(int);
void Curve_7(int);

void Fork_1(int);
void Fork_2(int);
void Fork_3(int);
void Fork_4(int);
void Fork_5(int);
void Fork_6(int);
void Fork_7(int);

void Sinker_1(int);
void Sinker_2(int);
void Sinker_3(int);
void Sinker_4(int);
void Sinker_5(int);
void Sinker_6(int);
void Sinker_7(int);

void Shoot_1(int);
void Shoot_2(int);
void Shoot_3(int);
void Shoot_4(int);
void Shoot_5(int);
void Shoot_6(int);
void Shoot_7(int);

void Daijyoubu(void);

void Pitcher_status_decide(void);
void Batter_status_decide(void);

void Pitcher_Ball_decide(void);
void Pitcher_Control_decide(void);
void Pitcher_Stamina_decide(void);
void Pitcher_Slider_decide(void);
void Pitcher_Curve_decide(void);
void Pitcher_Fork_decide(void);
void Pitcher_Sinker_decide(void);
void Pitcher_Shoot_decide(void);

void Batter_Trajectory_decide(void);
void Batter_Meet_decide(void);
void Batter_Power_decide(void);
void Batter_Run_decide(void);
void Batter_Sholder_decide(void);
void Batter_Protect_decide(void);
void Batter_Catching_decide(void);

void Pitcher_practice_decide(void);
void Batter_practice_decide(void);
void Pitcher_Point_allocate(void);
void Batter_Point_allocate(void);

void Prolog(void);

void Ball_point(void);
void Control_point(void);
void Stamina_point(void);
void Slider_point(void);
void Curve_point(void);
void Fork_point(void);
void Sinker_point(void);
void Shoot_point(void);

void Trajectory_point(void);
void Meet_point(void);
void Power_point(void);
void Run_point(void);
void Sholder_point(void);
void Protect_point(void);
void Catching_point(void);

void Pitcher_status(void);
void Batter_status(void);

//調子関数
void Feeling(void);

//運動型か非運動型か
void Type_sense(void);

//運動型、非運動型の内部
void Personality(void);

//顔関数
void Daijyoubu_success(void);
void Daijyoubu_fail(void);
void Pawapuro_normal(void);
void Pawapuro_happy(void);
void Pawapuro_surprise(void);
void Pawapuro_sad(void);
void Pawapuro_angry(void);

//運動型か非運動型かについての変数
//これを基本獲得経験点に加算する
int sense_point;
//運動型か非運動型か
// 1なら運動型、2なら非運動型
int sense;

string Name; //選手名
int Hp;      // 体力
int Position, sub_days, days, Number,
    practice_number; //ポジション、変数、経った日にち、背番号、練習項目番号
//能力値↓
int Ball, Control, Stamina, Slider, Curve, Fork, Sinker, Shoot, Trajectory,
    Meet, Power, Run, Sholder, Protect, Catching;
//練習レベル(投手)↓
int Ball_level = 1, Control_level = 1, Stamina_level = 1, Evolving_level = 1;
//練習レベル(野手)↓
int Meet_level = 1, Power_level = 1, Run_level = 1, Sholder_level = 1,
    Protect_level = 1, Catching_level = 1;
//練習レベルカウンター(投手)↓
int Ball_level_counter, Control_level_counter, Stamina_level_counter,
    Evolving_level_counter;
//練習レベルカウンター(野手)↓
int Meet_level_counter, Power_level_counter, Run_level_counter,
    Sholder_level_counter, Protect_level_counter, Catching_level_counter;
//能力値の評価(G,F,E,D,C,B,A,S)↓
char Control_status, Stamina_status, Trajectory_status, Meet_status,
    Power_status, Run_status, Sholder_status, Protect_status, Catching_status;
//変化球の評価(1,2,3,4,5,6,7)↓
int Slider_status, Curve_status, Fork_status, Sinker_status, Shoot_status;
int Ball_status, Ball_remainder;
int muscle, agile, technique, evolving, spirit; //筋力、敏捷、技術、変化球、精神
int muscle_point, agile_point, technique_point, evolving_point,
    spirit_point; //筋力、敏捷、技術、変化球、精神それぞれの獲得したポイント変数
int Trajectory_p, Meet_p, Power_p, Run_p, Sholder_p, Protect_p, Catching_p;
int Ball_p, Control_p, Stamina_p, Slider_p, Curve_p, Fork_p, Sinker_p, Shoot_p;

//各野手能力値の長さ変数
int length_Meet;
int length_Power;
int length_Run;
int length_Sholder;
int length_Protect;
int length_Catching;

//各投手能力値の長さ変数
int length_Control;
int length_Stamina;
int length_Ball;

string Position_name; //ポジション名
int condition, condition_point,
    prolog; //調子、調子による獲得ポイントの増減、プロログカウンター
int choise, genius,
    Daijyoubu_count; //リセット選択肢変数、天才型判定変数、ダイジョーブ博士出現回数変数
double genius_point; //天才型時必要経験値減係数変数
// ball_personalityの略、運動型、非運動型の内部
double ball_per = 1, control_per = 1, stamina_per = 1, evolving_per = 1,
       meet_per = 1, power_per = 1, run_per = 1, sholder_per = 1,
       protect_per = 1, catching_per = 1;

// インターリーブ学習のために過去の練習をカウントする
// インターリーブ学習の割合、最大で1.5ほどを想定している
double interleave_proportion = 0;
// 投手練習
int ball_interleave = 0, control_interleave = 0, stamina_interleave = 0,
    evolving_interleave = 0;

int main() {
    srand((unsigned)time(NULL));
GAME_START:
    system("clear");
    //タイトル表示
    cout << " ================================================================="
            "========== "
         << endl;
    cout << "| "
            "------------------------------------------------------------------"
            "------- |"
         << endl;
    cout << "||                                                      ＊＊      "
            "         ||"
         << endl;
    cout << "||                                                    ＊    ＊    "
            "     　  ||"
         << endl;
    cout << "||                  ＊＊                           ＊ ＊    ＊   "
            "　　　    ||"
         << endl;
    cout << "||                ＊    ＊                    ＊        ＊＊      "
            "         ||"
         << endl;
    cout << "||                ＊    ＊＊＊＊＊＊＊＊ ＊          ＊     ＊    "
            "         ||"
         << endl;
    cout << "||                  ＊＊                ＊      ＊    ＊       "
            "＊＊＊＊＊＊||"
         << endl;
    cout << "||      ＊＊    ＊ ＊      ＊＊＊＊＊    ＊＊         ＊    ＊    "
            "       ＊||"
         << endl;
    cout << "||     ＊   ＊  ＊  ＊     ＊      ＊    ＊           ＊   ＊＊ "
            "＊＊＊＊ ＊||"
         << endl;
    cout << "||    ＊   ＊   ＊  ＊ ＊＊        ＊    ＊          ＊      ＊ "
            "＊    ＊ ＊||"
         << endl;
    cout << "||   ＊   ＊    ＊   ＊           ＊    ＊          ＊    ＊ ＊ "
            "＊    ＊ ＊||"
         << endl;
    cout << "||  ＊   ＊     ＊    ＊         ＊    ＊          ＊        ＊ "
            "＊＊＊＊ ＊||"
         << endl;
    cout << "|| ＊   ＊      ＊     ＊       ＊    ＊          ＊    ＊   ＊   "
            "       ＊||"
         << endl;
    cout << "||＊ 　 ＊      ＊      ＊     ＊    ＊          ＊   ＊     "
            "＊＊＊＊＊＊＊||"
         << endl;
    cout << "||＊     ＊     ＊       ＊   ＊    ＊             ＊＊           "
            "         ||"
         << endl;
    cout << "|| ＊＊＊         ＊＊＊＊      ＊＊                              "
            "         ||"
         << endl;
    cout << "||                                                                "
            "         ||"
         << endl;
    cout << "||                         [1] ゲームスタート                     "
            "         ||"
         << endl;
    cout << "||                         [2] 終わる                             "
            "         ||"
         << endl;
    cout << "| "
            "------------------------------------------------------------------"
            "------- |"
         << endl;
    cout << " ================================================================="
            "========== "
         << endl;
    int ONOFF;
    cout << "項目を選んでね -> ";
    cin >> ONOFF;
    if(ONOFF == 2) {
        system("clear");
        exit(1);
    }
    if((ONOFF != 1) && (ONOFF != 2)) {
        if(getchar() == '\n')
            cout << "選択肢にあるもの選んでください。▼ ";
        if(getchar() == '\n')
            goto GAME_START;
    }
    if(getchar() == '\n')
        system("clear");
    cout << "[監督]:「君、名前なんだっけ？」▼ ";
    cout << endl;
    cout << "[名前]--> ";
    cin >> Name;
    cout << endl;
    if(getchar() == '\n')
        system("clear");
    cout << "[監督]:「背番号はなんだったっけ？」▼ ";
    cout << endl;
    cout << "[背番号]--> ";
    cin >> Number;
    cout << endl;
    if(getchar() == '\n')
        system("clear");
    cout << "[監督]:「ポジションはどこだっけ？」(数字を入力してください。)▼ "
         << endl;
    cout << "[1]投手、[2]捕手、[3]一塁手、[4]二塁手、[5]三塁手、[6]遊撃手、[7]"
            "左翼手、[8]中堅手、[9]右翼手 ▼ ";
    cout << endl;
    cout << "[ポジション]--> ";
    cin >> Position;
    if(getchar() == '\n') {
        system("clear");
        if(Position == 1)
            cout << "[監督]:「あ、そっかぁ。投手かぁ。まぁ頑張ってくれ。」▼ ";
        if(Position == 2) {
            Position_name = "捕手";
            cout << "[監督]:「あ、そっかぁ。捕手かぁ。まぁ頑張ってくれ。」▼ ";
        }
        if(Position == 3) {
            system("clear");
            Position_name = "一塁手";
            cout << "[監督]:「あ、そっかぁ。一塁手かぁ。まぁ頑張ってくれ。」▼ ";
        }
        if(Position == 4) {
            system("clear");
            Position_name = "二塁手";
            cout << "[監督]:「あ、そっかぁ。二塁手かぁ。まぁ頑張ってくれ。」▼ ";
        }
        if(Position == 5) {
            system("clear");
            Position_name = "三塁手";
            cout << "[監督]:「あ、そっかぁ。三塁手かぁ。まぁ頑張ってくれ。」▼ ";
        }
        if(Position == 6) {
            system("clear");
            Position_name = "遊撃手";
            cout << "[監督]:「あ、そっかぁ。遊撃手かぁ。まぁ頑張ってくれ。」▼ ";
        }
        if(Position == 7) {
            system("clear");
            Position_name = "左翼手";
            cout << "[監督]:「あ、そっかぁ。左翼手かぁ。まぁ頑張ってくれ。」▼ ";
        }
        if(Position == 8) {
            system("clear");
            Position_name = "中堅手";
            cout << "[監督]:「あ、そっかぁ。中堅手かぁ。まぁ頑張ってくれ。」▼ ";
        }
        if(Position == 9) {
            system("clear");
            Position_name = "右翼手";
            cout << "[監督]:「あ、そっかぁ。右翼手かぁ。まぁ頑張ってくれ。」▼ "
                 << endl;
        }
    }
    if(getchar() == '\n') {
        system("clear");
        cout << "[["
                "舞台は高校3年甲子園予選大会1ヶ月前。主人公はラストスパートをか"
                "けてチームを甲子園に導くことはできるのだろうか。]]▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_sad();
        cout << "[" << Name << "]:"
             << "「しかし1ヶ月前にもなって監督に名前もポジションも忘れられるな"
                "んて、これもうわっかんねぇなぁ。」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_angry();
        cout << "[" << Name << "]:"
             << "「とにかく明日からの練習頑張るぞ！」▼ ";
    }

    Hp = HP; // 体力を100(満タン)にここでする

    //------------[31日ループ_投手]-------------------------------------------------------------------
    if(Position == 1) {
    PITCHER:
        //運動型、非運動型
        // デバッグ用に強制的に運動型へ
        // sense = rand() % 2 + 1;
        sense = 1;
        //リセットの際の変化球習得初期化
        Slider = 0;
        Curve = 0;
        Fork = 0;
        Sinker = 0;
        Shoot = 0;
        // 天才型投手初期能力決定
        // genius = rand() % GENIUS_DENOMINATOR + 1;
        genius = 2;
        if(genius == 1) {
            genius_point = 0.9;
            Ball = 135 + (rand() % 14 + 1);
            Control = 45 + (rand() % 25 + 1);
            Stamina = 45 + (rand() % 25 + 1);
            int genius_decide_1;
            genius_decide_1 = rand() % 2 + 1;
            if(genius_decide_1 == 1) {
                int genius_decide_2;
                genius_decide_2 = rand() % 5 + 1;
                if(genius_decide_2 == 1)
                    Slider = 3;
                if(genius_decide_2 == 2)
                    Curve = 3;
                if(genius_decide_2 == 3)
                    Fork = 3;
                if(genius_decide_2 == 4)
                    Sinker = 3;
                if(genius_decide_2 == 5)
                    Shoot = 3;
            }
            if(genius_decide_1 == 2) {
                int genius_decide_2;
                genius_decide_2 = rand() % 10 + 1;
                if(genius_decide_2 == 1) {
                    Slider = 2;
                    Curve = 2;
                }
                if(genius_decide_2 == 2) {
                    Slider = 2;
                    Fork = 2;
                }
                if(genius_decide_2 == 3) {
                    Slider = 2;
                    Sinker = 2;
                }
                if(genius_decide_2 == 4) {
                    Slider = 2;
                    Shoot = 2;
                }
                if(genius_decide_2 == 5) {
                    Curve = 2;
                    Fork = 2;
                }
                if(genius_decide_2 == 6) {
                    Curve = 2;
                    Sinker = 2;
                }
                if(genius_decide_2 == 7) {
                    Curve = 2;
                    Shoot = 2;
                }
                if(genius_decide_2 == 8) {
                    Fork = 2;
                    Sinker = 2;
                }
                if(genius_decide_2 == 9) {
                    Fork = 2;
                    Shoot = 2;
                }
                if(genius_decide_2 == 10) {
                    Sinker = 2;
                    Shoot = 2;
                }
            }
        }
        //凡才投手初期能力決定
        else {
            genius_point = 1;
            Ball = 125 + (rand() % 14 + 1);
            Control = 10 + (rand() % 40 + 1);
            Stamina = 10 + (rand() % 40 + 1);

            //一定確率での変化球習得
            int decide_1;
            decide_1 = rand() % 10 + 1;
            if(decide_1 < 5) {
                int decide_2;
                decide_2 = rand() % 5 + 1;
                if(decide_2 == 1)
                    Slider = 1;
                if(decide_2 == 2)
                    Curve = 1;
                if(decide_2 == 3)
                    Fork = 1;
                if(decide_2 == 4)
                    Sinker = 1;
                if(decide_2 == 5)
                    Shoot = 1;
            }
        }

        while(1) {
            //各投手能力値の長さ判定
            if((Control >= 0) && (Control < 10))
                length_Control = 1;
            else if((Control >= 10) && (Control < 100))
                length_Control = 2;
            else
                length_Control = 3;

            if((Stamina >= 0) && (Stamina < 10))
                length_Stamina = 1;
            else if((Stamina >= 10) && (Stamina < 100))
                length_Stamina = 2;
            else
                length_Stamina = 3;

            if((Ball >= 0) && (Ball < 10))
                length_Ball = 1;
            else if((Ball >= 10) && (Ball < 100))
                length_Ball = 2;
            else
                length_Ball = 3;

            //野手能力画面の空白調節部分
            string Controlspan(4 - length_Control, ' ');
            string Staminaspan(4 - length_Stamina, ' ');
            string Ballspan(4 - length_Ball, ' ');

            days = DAYS - sub_days;
            if(getchar() == '\n') {
                system("clear");
            }

            // 調子決定行
            condition = rand() % 5 + 1;
            if(condition == 1)
                condition_point = -3;
            if(condition == 2)
                condition_point = -1;
            if(condition == 3)
                condition_point = 0;
            if(condition == 4)
                condition_point = 1;
            if(condition == 5)
                condition_point = 3;

            Pitcher_status_decide();

        //-----[投手ステータス]------------------------------------------------------------
        START_PITCHER:

            //運動型、非運動型判定===============================================

            Pitcher_status();

            // デバッグのため一時的にコメントアウト

            if((sense == 1) && (genius == 1)) {
                cout << " ========  ========" << endl;
                cout << "| 運動型 || 天才型 |" << endl;
                cout << " ========  ========" << endl;
            }
            if((sense == 2) && (genius == 1)) {
                cout << " ==========  ========" << endl;
                cout << "| 非運動型 || 天才型 |" << endl;
                cout << " ==========  ========" << endl;
            }
            if((sense == 1) && (genius == 2)) {
                cout << " ========  ========" << endl;
                cout << "| 運動型 || 凡才型 |" << endl;
                cout << " ========  ========" << endl;
            }
            if((sense == 2) && (genius == 2)) {
                cout << " ==========  ========" << endl;
                cout << "| 非運動型 || 凡才型 |" << endl;
                cout << " ==========  ========" << endl;
            }

            if(prolog == 0) {
                cout << "[監督]:「" << Name
                     << "は今の実力に満足しているかね？」▼ " << endl;
                cout << "[" << Name
                     << "]: [1]もちろんです！　[2]いや、こんなの僕じゃない！ ▼ "
                     << endl;
                cout << "選択 -> ";
                cin >> choise;
                if(choise == 2) {
                    system("clear");
                    goto PITCHER;
                }
                //特徴付け（投手）
                system("clear");
                Personality();

                Prolog();
                prolog++;
                goto START_PITCHER;
            }

            if(HP < Hp) {
                Hp = HP;
            } else if(Hp == 0) {
                Pawapuro_sad();
                cout << "[" << Name << "]" << endl;
                cout << "疲れてしまった…今日の練習は休んでしまおう…。" << endl;
                Hp += 70 + condition_point * 10;
                if(getchar() == '\n') {
                    cout << "休憩を行った。▼";
                }
                if(getchar() == '\n') {
                    cout << "\x1b[33m"
                         << "体力"
                         << "\x1b[34m"
                         << "が" << 70 + condition_point * 10 << "回復した。▼";
                }
                cout << "\x1b[39m"; //デフォ
            } else {

                cout << "[今日の練習は何をしよう？]" << endl;

                //誤差リセット
                Type_sense();

                if(Ball_level == 1)
                    cout << "[1]:シャドウピッチング(練習Lv.1)" << endl;
                if(Ball_level == 2)
                    cout << "[1]:投げ込み(練習Lv.2)" << endl;
                if(Ball_level == 3)
                    cout << "[1]:マッスラー(練習Lv.3)" << endl;
                if(Control_level == 1)
                    cout << "[2]:的当て(練習Lv.1)" << endl;
                if(Control_level == 2)
                    cout << "[2]:コース投げ込み(練習Lv.2)" << endl;
                if(Control_level == 3)
                    cout << "[2]:コース実践(練習Lv.3)" << endl;
                if(Stamina_level == 1)
                    cout << "[3]:長距離走(練習Lv.1)" << endl;
                if(Stamina_level == 2)
                    cout << "[3]:マラソン(練習Lv.2)" << endl;
                if(Stamina_level == 3)
                    cout << "[3]:タイヤ引き(練習Lv.3)" << endl;
                if(Evolving_level == 1)
                    cout << "[4]:変化球本音読(練習Lv.1)" << endl;
                if(Evolving_level == 2)
                    cout << "[4]:変化球投げ込み(練習Lv.2)" << endl;
                if(Evolving_level == 3)
                    cout << "[4]:変化球実践(練習Lv.3)" << endl;
                cout << "[5]:休憩" << endl;
                cout << "[0]:能力Up" << endl;
                cout << "[選択メニュー] -> ";
                cin >> practice_number;
                //選択肢が能力up
                if(practice_number == 0) {
                    Pitcher_Point_allocate();
                    goto START_PITCHER;
                }
                //選択肢が練習メニュー
                else if((practice_number > 0) && (practice_number < 6))
                    Pitcher_practice_decide();
                //選択肢以外
                else {
                    if(getchar() == '\n')
                        cout << "そんな番号はないです。▼ ";
                    if(getchar() == '\n')
                        goto START_PITCHER;
                }

                //ダイジョーブ博士関数移動
                if(Daijyoubu_count < 10) {
                    if((rand() % 10 + 1) < DAIJYOUBU_1)
                        Daijyoubu();
                    Daijyoubu_count++; //ダイジョーブ博士出現カウンター
                }
            }

            if(days == 1) {
                // 31日ループ終了と同時に結果をcsv出力
                cout << "終わるのだ" << endl;
                ofstream ofs("result.csv", std::ios::app);
                ofs << Position << "," << muscle << "," << agile << ","
                    << technique << "," << evolving << "," << spirit << endl;
                cout << Position << "," << muscle << "," << agile << ","
                     << technique << "," << evolving << "," << spirit << endl;
                break;
            }
            sub_days++;
        }
    }

    //------------[31日ループ_野手]-------------------------------------------------------------------
    if((Position >= 2) && (Position <= 9)) {
    BATTER:
        //運動型、非運動型
        sense = rand() % 2 + 1;
        //天才型野手初期能力決定
        genius = rand() % GENIUS_DENOMINATOR + 1;
        if(genius == 1) {
            genius_point = 0.9;
            Trajectory = 1 + rand() % 1 + 1;
            Meet = 45 + (rand() % 25 + 1);
            Power = 45 + (rand() % 25 + 1);
            Run = 45 + (rand() % 25 + 1);
            Sholder = 45 + (rand() % 25 + 1);
            Protect = 45 + (rand() % 25 + 1);
            Catching = 45 + (rand() % 25 + 1);
        }

        //凡才野手初期能力決定
        else {
            genius_point = 1;
            Trajectory = rand() % 1 + 1;
            Meet = 10 + (rand() % 40 + 1);
            Power = 10 + (rand() % 40 + 1);
            Run = 10 + (rand() % 40 + 1);
            Sholder = 10 + (rand() % 40 + 1);
            Protect = 10 + (rand() % 40 + 1);
            Catching = 10 + (rand() % 40 + 1);
        }

        while(1) {
            days = DAYS - sub_days;
            if(getchar() == '\n') {
                system("clear");
            }

            condition = rand() % 5 + 1; //調子決定行
            if(condition == 1)
                condition_point = -3;
            if(condition == 2)
                condition_point = -1;
            if(condition == 3)
                condition_point = 0;
            if(condition == 4)
                condition_point = 1;
            if(condition == 5)
                condition_point = 3;

            Batter_status_decide();

            //-----[野手ステータス]---------------------------------------------------------------------------
        START_BATTER:

            //運動型、非運動型判定===============================================

            Batter_status();
            //デバッグのため一時的にコメントアウト
            /*
            if ((sense == 1) && (genius == 1))
            {
              cout << " ========  ========" << endl;
              cout << "| 運動型 || 天才型 |" << endl;
              cout << " ========  ========" << endl;
            }
            if ((sense == 2) && (genius == 1))
            {
              cout << " ==========  ========" << endl;
              cout << "| 非運動型 || 天才型 |" << endl;
              cout << " ==========  ========" << endl;
            }
            if ((sense == 1) && (genius == 2))
            {
              cout << " ========  ========" << endl;
              cout << "| 運動型 || 凡才型 |" << endl;
              cout << " ========  ========" << endl;
            }
            if ((sense == 2) && (genius == 2))
            {
              cout << " ==========  ========" << endl;
              cout << "| 非運動型 || 凡才型 |" << endl;
              cout << " ==========  ========" << endl;
            }
             */

            //リセット判定
            if(prolog == 0) {
                cout << "[監督]:「" << Name
                     << "は今の実力に満足しているかね？」▼ " << endl;
                cout << "[" << Name
                     << "]: [1]もちろんです！　[2]いや、こんなの僕じゃない！ ▼ "
                     << endl;
                cout << "選択 -> ";
                cin >> choise;
                if(choise == 2) {
                    system("clear");
                    goto BATTER;
                }

                //特徴付け（野手）
                system("clear");
                Personality();

                Prolog();
                prolog++;
                goto START_BATTER;
            }

            cout << "[今日の練習は何をしよう？]" << endl;

            //誤差リセット
            Type_sense();

            if(Meet_level == 1)
                cout << "[1]:素振り(打撃Lv.1)" << endl;
            if(Meet_level == 2)
                cout << "[1]:ティーバッティング(打撃Lv.2)" << endl;
            if(Meet_level == 3)
                cout << "[1]:シートバッティング(打撃Lv.3)" << endl;
            if(Power_level == 1)
                cout << "[2]:腹筋(筋力Lv.1)" << endl;
            if(Power_level == 2)
                cout << "[2]:ダンベル(筋力Lv.2)" << endl;
            if(Power_level == 3)
                cout << "[2]:ベンチプレス(筋力Lv.3)" << endl;
            if(Run_level == 1)
                cout << "[3]:短距離走(走塁Lv.1)" << endl;
            if(Run_level == 2)
                cout << "[3]:ゴム引き走(走塁Lv.2)" << endl;
            if(Run_level == 3)
                cout << "[3]:ベースランニング(走塁Lv.3)" << endl;
            if(Sholder_level == 1)
                cout << "[4]:キャッチボール(肩力Lv.1)" << endl;
            if(Sholder_level == 2)
                cout << "[4]:遠投(肩力Lv.2)" << endl;
            if(Sholder_level == 3)
                cout << "[4]:レーザービームの極意(肩力Lv.3)" << endl;
            if(Protect_level == 1)
                cout << "[5]:守備基本練習(守備Lv.1)" << endl;
            if(Protect_level == 2)
                cout << "[5]:ノック(守備Lv.2)" << endl;
            if(Protect_level == 3)
                cout << "[5]:実践守備(守備Lv.3)" << endl;
            if(Catching_level == 1)
                cout << "[6]:精神練習(精神Lv.1)" << endl;
            if(Catching_level == 2)
                cout << "[6]:メンタル練習(精神Lv.2)" << endl;
            if(Catching_level == 3)
                cout << "[6]:めいそう(精神Lv.3)" << endl;
            cout << "[0]:能力Up" << endl;
            cout << "[選択メニュー] -> ";
            cin >> practice_number;
            //選択肢が能力up
            if(practice_number == 0) {
                Batter_Point_allocate();
                goto START_BATTER;
            }
            //選択肢が練習メニュー
            else if((practice_number > 0) && (practice_number < 7))
                Batter_practice_decide();
            //選択肢以外
            else {
                if(getchar() == '\n')
                    cout << "そんな番号はないです。▼ ";
                if(getchar() == '\n')
                    goto START_BATTER;
            }

            //ダイジョーブ博士関数移動
            if(Daijyoubu_count < 10) {
                if((rand() % 10 + 1) < DAIJYOUBU_1)
                    Daijyoubu();
                Daijyoubu_count++; //ダイジョーブ博士出現カウンター
            }
            if(days == 1)
                break;
            sub_days++;
        }
    }
    cout << "\x1b[39m";
    return (0);
}

//======[関数群]=======================================================================================-

//「運動型」「非運動型」に関しての関数
void Type_sense(void) {
    int sense_decide = 0;
    if(sense == 1) { //運動型
        sense_decide = rand() % 10 + 1;
        if(sense_decide < 4) { // 1~3(30%)
            int div = 0;
            div = rand() % 100 + 1;
            if(div < 26)
                sense_point = 1;
            else if(div < 76)
                sense_point = 2;
            else
                sense_point = 3;
        } else if(sense_decide < 7) { // 4~7(30%)
            int div = 0;
            div = rand() % 100 + 1;
            if(div < 21)
                sense_point = 4;
            else if(div < 51)
                sense_point = 5;
            else if(div < 81)
                sense_point = 6;
            else
                sense_point = 7;
        } else { // 8~10(40%)
            int div = 0;
            div = rand() % 100 + 1;
            if(div < 26)
                sense_point = 8;
            else if(div < 76)
                sense_point = 9;
            else
                sense_point = 10;
        }
    } //運動型終了

    else { //非運動型
        sense_decide = rand() % 10 + 1;
        if(sense_decide < 5) { // 1~3(40%)
            int div = 0;
            div = rand() % 100 + 1;
            if(div < 26)
                sense_point = 1;
            else if(div < 76)
                sense_point = 2;
            else
                sense_point = 3;
        } else if(sense_decide < 8) { // 4~7(30%)
            int div = 0;
            div = rand() % 100 + 1;
            if(div < 21)
                sense_point = 4;
            else if(div < 51)
                sense_point = 5;
            else if(div < 81)
                sense_point = 6;
            else
                sense_point = 7;
        } else { // 8~10(30%)
            int div = 0;
            div = rand() % 100 + 1;
            if(div < 26)
                sense_point = 8;
            else if(div < 76)
                sense_point = 9;
            else
                sense_point = 10;
        }
    } //非運動型終了
} //「運動型」「非運動型」に関しての関数終了

void Personality(void) {
    int pitcher_per, batter_per;
PERSONALITY:
    cout << "何に特化した選手になりたいんじゃ？ ▼" << endl;
    if(Position == 1) {
        cout << "[1] 力で勝負！球速派" << endl;
        cout << "[2] 技術で勝負！制球派" << endl;
        cout << "[3] 根性が一番！体力派" << endl;
        cout << "[4] 打者を翻弄！変化球派" << endl;
        cout << "select -> ";
        cin >> pitcher_per;
        if(pitcher_per == 1)
            ball_per = 0.9;
        else if(pitcher_per == 2)
            control_per = 0.9;
        else if(pitcher_per == 3)
            stamina_per = 0.9;
        else if(pitcher_per == 4)
            evolving_per = 0.9;
        else {
            if(getchar() == '\n')
                cout << "ちゃんと選びなさい ▼";
            if(getchar() == '\n') {
                system("clear");
                goto PERSONALITY;
            }
        }
    } else {
        cout << "[1] 確実性が一番！ミート派" << endl;
        cout << "[2] 力で勝負！パワー派" << endl;
        cout << "[3] 機動力で翻弄！走力派" << endl;
        cout << "[4] 走者を釘付け！肩力派" << endl;
        cout << "[5] まるで安田大サーカス！守備力派" << endl;
        cout << "[6] ミスしたことがない！捕球派" << endl;
        cout << "select -> ";
        cin >> batter_per;
        if(batter_per == 1)
            meet_per = 0.9;
        else if(batter_per == 2)
            power_per = 0.9;
        else if(batter_per == 3)
            run_per = 0.9;
        else if(batter_per == 4)
            sholder_per = 0.9;
        else if(batter_per == 5)
            protect_per = 0.9;
        else if(batter_per == 6)
            catching_per = 0.9;
        else {
            if(getchar() == '\n')
                cout << "ちゃんと選びなさい ▼";
            if(getchar() == '\n') {
                system("clear");
                goto PERSONALITY;
            }
        }
    }
}

void Pitcher_practice_decide(void) {
    // デバッグのインターリーブ学習をを表示
    cout << "interleave_% is " << interleave_proportion << endl;
    // インターリーブ率廃止
    interleave_proportion = 0;
    //-----[球速練習関連]------------------------------------------------------
    if(practice_number == 1) {
        if(Ball_level == 1) {
            muscle_point = BALL1[0] + sense_point;
            muscle_point += (int)(muscle_point * interleave_proportion);
            muscle += muscle_point;
            technique_point = BALL1[1] + sense_point;
            technique_point += (int)(technique_point * interleave_proportion);
            technique += technique_point;
            spirit_point = BALL1[2] + sense_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Ball_level_counter++;
            Hp -= LEVEL1_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "投げ込みを行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL1_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        if(Ball_level == 2) {
            muscle_point = BALL2[0] + sense_point + condition_point;
            muscle_point += (int)(muscle_point * interleave_proportion);
            muscle += muscle_point;
            technique_point = BALL2[1] + sense_point + condition_point;
            technique_point += (int)(technique_point * interleave_proportion);
            technique += technique_point;
            spirit_point = BALL2[2] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Ball_level_counter++;
            Hp -= LEVEL2_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "200球投げ込みを行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL2_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        if(Ball_level == 3) {
            muscle_point = BALL3[0] + sense_point + condition_point;
            muscle_point += (int)(muscle_point * interleave_proportion);
            muscle += muscle_point;
            technique_point = BALL3[1] + sense_point + condition_point;
            technique_point += (int)(technique_point * interleave_proportion);
            technique += technique_point;
            spirit_point = BALL3[2] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Hp -= LEVEL3_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "マッスラー投げ込みを行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL3_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        control_interleave--;
        stamina_interleave--;
        evolving_interleave--;
        if(control_interleave < 0) {
            control_interleave = 0;
        }
        if(stamina_interleave < 0) {
            stamina_interleave = 0;
        }
        if(evolving_interleave < 0) {
            evolving_interleave = 0;
        }
        if(ball_interleave == 4) {
            interleave_proportion = (0 + control_interleave +
                                     stamina_interleave + evolving_interleave) *
                                    INTERLEAVE_PROPORTION;
        } else {
            ball_interleave = 4;
            interleave_proportion = (ball_interleave + control_interleave +
                                     stamina_interleave + evolving_interleave) *
                                    INTERLEAVE_PROPORTION;
        }
    }
    if(Ball_level_counter == 3) {
        Ball_level_counter = 0;
        Ball_level++;
        if(Ball_level > 3) {
            Ball_level = 3;
        }
    }

    //-----[コントロール練習関連]------------------------------------------------------
    if(practice_number == 2) {
        if(Control_level == 1) {
            technique_point = CONTROL1[0] + sense_point + condition_point;
            technique_point += (int)(technique_point * interleave_proportion);
            technique += technique_point;
            spirit_point = CONTROL1[1] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Control_level_counter++;
            Hp -= LEVEL1_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "的当てを行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL1_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        if(Control_level == 2) {
            technique_point = CONTROL2[0] + sense_point + condition_point;
            technique_point += (int)(technique_point * interleave_proportion);
            technique += technique_point;
            spirit_point = CONTROL2[1] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Control_level_counter++;
            Hp -= LEVEL2_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "コース投げ込みを行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL2_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        if(Control_level == 3) {
            technique_point = CONTROL3[0] + sense_point + condition_point;
            technique_point += (int)(technique_point * interleave_proportion);
            technique += technique_point;
            spirit_point = CONTROL3[1] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Hp -= LEVEL3_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "コース実践行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL3_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        ball_interleave--;
        stamina_interleave--;
        evolving_interleave--;
        if(ball_interleave < 0) {
            ball_interleave = 0;
        }
        if(stamina_interleave < 0) {
            stamina_interleave = 0;
        }
        if(evolving_interleave < 0) {
            evolving_interleave = 0;
        }
        if(control_interleave == 4) {
            interleave_proportion = (ball_interleave + 0 + stamina_interleave +
                                     evolving_interleave) *
                                    INTERLEAVE_PROPORTION;
        } else {
            control_interleave = 4;
            interleave_proportion = (ball_interleave + control_interleave +
                                     stamina_interleave + evolving_interleave) *
                                    INTERLEAVE_PROPORTION;
        }
    }
    if(Control_level_counter == 3) {
        Control_level_counter = 0;
        Control_level++;
        if(Control_level > 3) {
            Control_level = 3;
        }
    }

    //-----[スタミナ練習関連]------------------------------------------------------
    int Stamina_add;
    if(practice_number == 3) {
        if(Stamina_level == 1) {
            muscle_point = STAMINA1[0] + sense_point + condition_point;
            muscle_point += (int)(muscle_point * interleave_proportion);
            muscle += muscle_point;
            spirit_point = STAMINA1[1] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Stamina_add += STAMINA1[2] + rand() % STAMINA1[3];
            Stamina_add += (int)(Stamina_add * interleave_proportion);
            Stamina += Stamina_add;
            Stamina_level_counter++;
            Hp -= LEVEL1_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "長距離走を行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "スタミナ"
                     << "\x1b[34m"
                     << "が" << Stamina_add << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL1_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        if(Stamina_level == 2) {
            muscle_point = STAMINA2[0] + sense_point + condition_point;
            muscle_point += (int)(muscle_point * interleave_proportion);
            muscle += muscle_point;
            spirit_point = STAMINA2[1] + sense_point + condition_point;
            spirit_point +=
                (int)(interleave_proportion * interleave_proportion);
            spirit += spirit_point;
            Stamina_add += STAMINA2[2] + rand() % STAMINA2[3];
            Stamina_add += (int)(Stamina_add * interleave_proportion);
            Stamina += Stamina_add;
            Stamina_level_counter++;
            Hp -= LEVEL2_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "マラソンを行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "スタミナ"
                     << "\x1b[34m"
                     << "が" << Stamina_add << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL2_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        if(Stamina_level == 3) {
            muscle_point = STAMINA3[0] + sense_point + condition_point;
            muscle_point += (int)(muscle_point * interleave_proportion);
            muscle += muscle_point;
            spirit_point = STAMINA3[1] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Stamina_add += STAMINA3[2] + rand() % STAMINA3[3];
            Stamina_add += (int)(Stamina_add * interleave_proportion);
            Stamina += Stamina_add;
            Hp -= LEVEL3_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "タイヤ引きを行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "スタミナ"
                     << "\x1b[34m"
                     << "が" << Stamina_add << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL3_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        ball_interleave--;
        control_interleave--;
        evolving_interleave--;
        if(ball_interleave < 0) {
            ball_interleave = 0;
        }
        if(control_interleave < 0) {
            control_interleave = 0;
        }
        if(evolving_interleave < 0) {
            evolving_interleave = 0;
        }
        if(stamina_interleave == 4) {
            interleave_proportion = (ball_interleave + control_interleave + 0 +
                                     evolving_interleave) *
                                    INTERLEAVE_PROPORTION;
        } else {
            stamina_interleave = 4;
            interleave_proportion = (ball_interleave + control_interleave +
                                     stamina_interleave + evolving_interleave) *
                                    INTERLEAVE_PROPORTION;
        }
    }
    if(Stamina_level_counter == 3) {
        Stamina_level_counter = 0;
        Stamina_level++;
        if(Stamina_level > 3) {
            Stamina_level = 3;
        }
    }

    //-----[変化球練習関連]------------------------------------------------------
    if(practice_number == 4) {
        if(Evolving_level == 1) {
            evolving_point = EVOLVING1[0] + sense_point + condition_point;
            evolving_point += (int)(evolving_point * interleave_proportion);
            evolving += evolving_point;
            technique_point = EVOLVING1[1] + sense_point + condition_point;
            technique_point += (int)(technique_point * interleave_proportion);
            technique += technique_point;
            spirit_point = EVOLVING1[2] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Evolving_level_counter++;
            Hp -= LEVEL1_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "変化球本音読を行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "変化球ポイント"
                     << "\x1b[34m"
                     << "が" << evolving_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL1_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        if(Evolving_level == 2) {
            evolving_point = EVOLVING2[0] + sense_point + condition_point;
            evolving_point += (int)(evolving_point * interleave_proportion);
            evolving += evolving_point;
            technique_point = EVOLVING2[1] + sense_point + condition_point;
            technique_point += (int)(technique_point * interleave_proportion);
            technique += technique_point;
            spirit_point = EVOLVING2[2] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Evolving_level_counter++;
            Hp -= LEVEL2_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "変化球投げ込みを行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "変化球ポイント"
                     << "\x1b[34m"
                     << "が" << evolving_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL2_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        if(Evolving_level == 3) {
            evolving_point = EVOLVING3[0] + sense_point + condition_point;
            evolving_point += (int)(evolving_point * interleave_proportion);
            evolving += evolving_point;
            technique_point = EVOLVING3[1] + sense_point + condition_point;
            technique_point += (int)(technique_point * interleave_proportion);
            technique += technique_point;
            spirit_point = EVOLVING3[2] + sense_point + condition_point;
            spirit_point += (int)(spirit_point * interleave_proportion);
            spirit += spirit_point;
            Hp -= LEVEL3_PRACTICE_HP - condition_point;
            if(getchar() == '\n') {
                cout << "変化球実践を行なった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "変化球ポイント"
                     << "\x1b[34m"
                     << "が" << evolving_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            }
            if(getchar() == '\n') {
                cout << "\x1b[33m"
                     << "体力"
                     << "\x1b[34m"
                     << "が" << LEVEL3_PRACTICE_HP - condition_point
                     << "下がった。▼";
            }
            cout << "\x1b[39m"; //デフォ
        }
        ball_interleave--;
        control_interleave--;
        stamina_interleave--;
        if(ball_interleave < 0) {
            ball_interleave = 0;
        }
        if(control_interleave < 0) {
            control_interleave = 0;
        }
        if(stamina_interleave < 0) {
            stamina_interleave = 0;
        }
        if(evolving_interleave == 4) {
            interleave_proportion = (ball_interleave + control_interleave +
                                     stamina_interleave + 0) *
                                    INTERLEAVE_PROPORTION;
        } else {
            evolving_interleave = 4;
            interleave_proportion = (ball_interleave + control_interleave +
                                     stamina_interleave + evolving_interleave) *
                                    INTERLEAVE_PROPORTION;
        }
    }
    if(Evolving_level_counter == 3) {
        Evolving_level_counter = 0;
        Evolving_level++;
        if(Evolving_level > 3) {
            Evolving_level = 3;
        }
    }

    //-----[休憩]-----------------------------------------
    if(practice_number == 5) {
        Hp += 70 + condition_point * 10;
        if(getchar() == '\n') {
            cout << "休憩を行った。▼";
        }
        if(getchar() == '\n') {
            cout << "\x1b[33m"
                 << "体力"
                 << "\x1b[34m"
                 << "が" << 70 + condition_point * 10 << "回復した。▼";
        }
    }

    cout << endl;
    cout << "LEVEL1 減少HP is" << LEVEL1_PRACTICE_HP - condition_point << endl;
    cout << "LEVEL2 減少HP is" << LEVEL2_PRACTICE_HP - condition_point << endl;
    cout << "LEVEL3 減少HP is" << LEVEL3_PRACTICE_HP - condition_point << endl;
    cout << "ball_interleave is " << ball_interleave << endl;
    cout << "control_interleave is " << control_interleave << endl;
    cout << "stamina_interleave is " << stamina_interleave << endl;
    cout << "evolving_interleave is " << evolving_interleave << endl;
    cout << "\x1b[39m"; //デフォ
}

void Batter_practice_decide(void) {

    //-----[打撃練習関連]------------------------------------------------------
    if(practice_number == 1) {
        if(Meet_level == 1) {
            muscle_point = 3 + sense_point + condition_point;
            muscle += muscle_point;
            technique_point = 10 + sense_point + condition_point;
            technique += technique_point;
            spirit_point = 3 + sense_point + condition_point;
            spirit += spirit_point;
            Meet_level_counter++;
            if(getchar() == '\n')
                cout << "素振りを行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Meet_level == 2) {
            muscle_point = 6 + sense_point + condition_point;
            muscle += muscle_point;
            technique_point = 13 + sense_point + condition_point;
            technique += technique_point;
            spirit_point = 6 + sense_point + condition_point;
            spirit += spirit_point;
            Meet_level_counter++;
            if(getchar() == '\n')
                cout << "ティーバッティングを行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Meet_level == 3) {
            muscle_point = 10 + sense_point + condition_point;
            muscle += muscle_point;
            technique_point = 17 + sense_point + condition_point;
            technique += technique_point;
            spirit_point = 10 + sense_point + condition_point;
            spirit += spirit_point;
            if(getchar() == '\n')
                cout << "シートバッティングを行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
    }
    if(Meet_level_counter == 3) {
        Meet_level_counter = 0;
        if(Meet_level == 1)
            Meet_level = 2;
        else if(Meet_level == 2)
            Meet_level = 3;
        else
            Meet_level = 3;
    }

    //-----[筋力練習関連]------------------------------------------------------
    if(practice_number == 2) {
        if(Power_level == 1) {
            muscle_point = 15 + sense_point + condition_point;
            muscle += muscle_point;
            spirit_point = 3 + sense_point + condition_point;
            spirit += spirit_point;
            Power_level_counter++;
            if(getchar() == '\n')
                cout << "腹筋を行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Power_level == 2) {
            muscle_point = 20 + sense_point + condition_point;
            muscle += muscle_point;
            spirit_point = 6 + sense_point + condition_point;
            spirit += spirit_point;
            Power_level_counter++;
            if(getchar() == '\n')
                cout << "ダンベルを行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Power_level == 3) {
            muscle_point = 25 + sense_point + condition_point;
            muscle += muscle_point;
            spirit_point = 10 + sense_point + condition_point;
            spirit += spirit_point;
            if(getchar() == '\n')
                cout << "ベンチプレスを行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
    }
    if(Power_level_counter == 3) {
        Power_level_counter = 0;
        if(Power_level == 1)
            Power_level = 2;
        else if(Power_level == 2)
            Power_level = 3;
        else
            Power_level = 3;
    }

    //-----[走塁練習関連]------------------------------------------------------
    if(practice_number == 3) {
        if(Run_level == 1) {
            muscle_point = 3 + sense_point + condition_point;
            muscle += muscle_point;
            agile_point = 15 + sense_point + condition_point;
            agile += agile_point;
            Run_level_counter++;
            if(getchar() == '\n')
                cout << "短距離走を行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "敏捷ポイント"
                     << "\x1b[34m"
                     << "が" << agile_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Run_level == 2) {
            muscle_point = 6 + sense_point + condition_point;
            muscle += muscle_point;
            agile_point = 20 + sense_point + condition_point;
            agile += agile_point;
            Run_level_counter++;
            if(getchar() == '\n')
                cout << "ゴム引き走を行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "敏捷ポイント"
                     << "\x1b[34m"
                     << "が" << agile_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Run_level == 3) {
            muscle_point = 10 + sense_point + condition_point;
            muscle += muscle_point;
            agile_point = 25 + sense_point + condition_point;
            agile += agile_point;
            if(getchar() == '\n')
                cout << "ベースランニングを行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "敏捷ポイント"
                     << "\x1b[34m"
                     << "が" << agile_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
    }
    if(Run_level_counter == 3) {
        Run_level_counter = 0;
        if(Run_level == 1)
            Run_level = 2;
        else if(Run_level == 2)
            Run_level = 3;
        else
            Run_level = 3;
    }

    //-----[肩力練習関連]------------------------------------------------------
    if(practice_number == 4) {
        if(Sholder_level == 1) {
            muscle_point = 10 + sense_point + condition_point;
            muscle += muscle_point;
            agile_point = 3 + sense_point + condition_point;
            agile += agile_point;
            technique_point = 3 + sense_point + condition_point;
            technique += technique_point;
            Sholder_level_counter++;
            if(getchar() == '\n')
                cout << "キャッチボールを行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Sholder_level == 2) {
            muscle_point = 13 + sense_point + condition_point;
            muscle += muscle_point;
            agile_point = 6 + sense_point + condition_point;
            agile += agile_point;
            technique_point = 6 + sense_point + condition_point;
            technique += technique_point;
            Sholder_level_counter++;
            if(getchar() == '\n')
                cout << "遠投を行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Sholder_level == 3) {
            muscle_point = 17 + sense_point + condition_point;
            muscle += muscle_point;
            agile_point = 10 + sense_point + condition_point;
            agile += agile_point;
            technique_point = 10 + sense_point + condition_point;
            technique += technique_point;
            if(getchar() == '\n')
                cout << "レーザービームの極意を行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "筋力ポイント"
                     << "\x1b[34m"
                     << "が" << muscle_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
    }
    if(Sholder_level_counter == 3) {
        Sholder_level_counter = 0;
        if(Sholder_level == 1)
            Sholder_level = 2;
        else if(Sholder_level == 2)
            Sholder_level = 3;
        else
            Sholder_level = 3;
    }

    //-----[守備練習関連]------------------------------------------------------
    if(practice_number == 5) {
        if(Sholder_level == 1) {
            agile_point = 3 + sense_point + condition_point;
            agile += agile_point;
            technique_point = 10 + sense_point + condition_point;
            technique += technique_point;
            spirit_point = 3 + sense_point + condition_point;
            spirit += spirit_point;
            Protect_level_counter++;
            if(getchar() == '\n')
                cout << "守備基本練習を行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "敏捷ポイント"
                     << "\x1b[34m"
                     << "が" << agile_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Sholder_level == 2) {
            agile_point = 6 + sense_point + condition_point;
            agile += agile_point;
            technique_point = 13 + sense_point + condition_point;
            technique += technique_point;
            spirit_point = 6 + sense_point + condition_point;
            spirit += spirit_point;
            Protect_level_counter++;
            if(getchar() == '\n')
                cout << "ノックを行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "敏捷ポイント"
                     << "\x1b[34m"
                     << "が" << agile_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Sholder_level == 3) {
            agile_point = 10 + sense_point + condition_point;
            agile += agile_point;
            technique_point = 17 + sense_point + condition_point;
            technique += technique_point;
            spirit_point = 10 + sense_point + condition_point;
            spirit += spirit_point;
            if(getchar() == '\n')
                cout << "実践守備を行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "敏捷ポイント"
                     << "\x1b[34m"
                     << "が" << agile_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
    }
    if(Protect_level_counter == 3) {
        Protect_level_counter = 0;
        if(Protect_level == 1)
            Protect_level = 2;
        else if(Protect_level == 2)
            Protect_level = 3;
        else
            Protect_level = 3;
    }

    //-----[精神練習関連]------------------------------------------------------
    if(practice_number == 6) {
        if(Catching_level == 1) {
            technique_point = 3 + sense_point + condition_point;
            technique += technique_point;
            spirit_point = 15 + sense_point + condition_point;
            spirit += spirit_point;
            Catching_level_counter++;
            if(getchar() == '\n')
                cout << "精神練習を行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Catching_level == 2) {
            technique_point = 6 + sense_point + condition_point;
            technique += technique_point;
            spirit_point = 20 + sense_point + condition_point;
            spirit += spirit_point;
            Catching_level_counter++;
            if(getchar() == '\n')
                cout << "メンタル練習を行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
        if(Catching_level == 3) {
            technique_point = 10 + sense_point + condition_point;
            technique += technique_point;
            spirit_point = 25 + sense_point + condition_point;
            spirit += spirit_point;
            if(getchar() == '\n')
                cout << "めいそうを行なった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "技術ポイント"
                     << "\x1b[34m"
                     << "が" << technique_point << "上がった。▼ ";
            if(getchar() == '\n')
                cout << "\x1b[33m"
                     << "精神ポイント"
                     << "\x1b[34m"
                     << "が" << spirit_point << "上がった。▼ ";
            cout << "\x1b[39m"; //デフォ
        }
    }
    if(Catching_level_counter == 3) {
        Catching_level_counter = 0;
        if(Catching_level == 1)
            Catching_level = 2;
        else if(Catching_level == 2)
            Catching_level = 3;
        else
            Catching_level = 3;
    }
}

void Pitcher_status_decide(void) {

    //-----[コントロール判定]-----------------------------------
    if(Control >= 90)
        Control_status = 'S';
    if((Control >= 80) && (Control < 90))
        Control_status = 'A';
    if((Control >= 70) && (Control < 80))
        Control_status = 'B';
    if((Control >= 60) && (Control < 70))
        Control_status = 'C';
    if((Control >= 50) && (Control < 60))
        Control_status = 'D';
    if((Control >= 40) && (Control < 50))
        Control_status = 'E';
    if((Control >= 20) && (Control < 40))
        Control_status = 'F';
    if(Control < 20)
        Control_status = 'G';

    //-----[スタミナ判定]---------------------------------------
    if(Stamina >= 90)
        Stamina_status = 'S';
    if((Stamina >= 80) && (Stamina < 90))
        Stamina_status = 'A';
    if((Stamina >= 70) && (Stamina < 80))
        Stamina_status = 'B';
    if((Stamina >= 60) && (Stamina < 70))
        Stamina_status = 'C';
    if((Stamina >= 50) && (Stamina < 60))
        Stamina_status = 'D';
    if((Stamina >= 40) && (Stamina < 50))
        Stamina_status = 'E';
    if((Stamina >= 20) && (Stamina < 40))
        Stamina_status = 'F';
    if(Stamina < 20)
        Stamina_status = 'G';

    //-----[スライダー判定]-----------------------------------------
    if(Slider == 7)
        Slider_status = 7;
    if(Slider == 6)
        Slider_status = 6;
    if(Slider == 5)
        Slider_status = 5;
    if(Slider == 4)
        Slider_status = 4;
    if(Slider == 3)
        Slider_status = 3;
    if(Slider == 2)
        Slider_status = 2;
    if(Slider == 1)
        Slider_status = 1;
    if(Slider == 0)
        Slider_status = 0;

    //-----[カーブ判定]-----------------------------------------
    if(Curve == 7)
        Curve_status = 7;
    if(Curve == 6)
        Curve_status = 6;
    if(Curve == 5)
        Curve_status = 5;
    if(Curve == 4)
        Curve_status = 4;
    if(Curve == 3)
        Curve_status = 3;
    if(Curve == 2)
        Curve_status = 2;
    if(Curve == 1)
        Curve_status = 1;
    if(Curve == 0)
        Curve_status = 0;

    //-----[フォーク判定]-----------------------------------------
    if(Fork == 7)
        Fork_status = 7;
    if(Fork == 6)
        Fork_status = 6;
    if(Fork == 5)
        Fork_status = 5;
    if(Fork == 4)
        Fork_status = 4;
    if(Fork == 3)
        Fork_status = 3;
    if(Fork == 2)
        Fork_status = 2;
    if(Fork == 1)
        Fork_status = 1;
    if(Fork == 0)
        Fork_status = 0;

    //-----[シンカー判定]-----------------------------------------
    if(Sinker == 7)
        Sinker_status = 7;
    if(Sinker == 6)
        Sinker_status = 6;
    if(Sinker == 5)
        Sinker_status = 5;
    if(Sinker == 4)
        Sinker_status = 4;
    if(Sinker == 3)
        Sinker_status = 3;
    if(Sinker == 2)
        Sinker_status = 2;
    if(Sinker == 1)
        Sinker_status = 1;
    if(Sinker == 0)
        Sinker_status = 0;

    //-----[シュート判定]-----------------------------------------
    if(Shoot == 7)
        Shoot_status = 7;
    if(Shoot == 6)
        Shoot_status = 6;
    if(Shoot == 5)
        Shoot_status = 5;
    if(Shoot == 4)
        Shoot_status = 4;
    if(Shoot == 3)
        Shoot_status = 3;
    if(Shoot == 2)
        Shoot_status = 2;
    if(Shoot == 1)
        Shoot_status = 1;
    if(Shoot == 0)
        Shoot_status = 0;
}

void Batter_status_decide(void) {
    //-----[弾道判定]-----------------------------------------
    if(Trajectory == 4)
        Trajectory_status = '4';
    if(Trajectory == 3)
        Trajectory_status = '3';
    if(Trajectory == 2)
        Trajectory_status = '2';
    if(Trajectory == 1)
        Trajectory_status = '1';

    //-----[ミート判定]---------------------------------------
    if(Meet >= 90)
        Meet_status = 'S';
    if((Meet >= 80) && (Meet < 90))
        Meet_status = 'A';
    if((Meet >= 70) && (Meet < 80))
        Meet_status = 'B';
    if((Meet >= 60) && (Meet < 70))
        Meet_status = 'C';
    if((Meet >= 50) && (Meet < 60))
        Meet_status = 'D';
    if((Meet >= 40) && (Meet < 50))
        Meet_status = 'E';
    if((Meet >= 20) && (Meet < 40))
        Meet_status = 'F';
    if(Meet < 20)
        Meet_status = 'G';

    //-----[パワー判定]---------------------------------------
    if(Power >= 90)
        Power_status = 'S';
    if((Power >= 80) && (Power < 90))
        Power_status = 'A';
    if((Power >= 70) && (Power < 80))
        Power_status = 'B';
    if((Power >= 60) && (Power < 70))
        Power_status = 'C';
    if((Power >= 50) && (Power < 60))
        Power_status = 'D';
    if((Power >= 40) && (Power < 50))
        Power_status = 'E';
    if((Power >= 20) && (Power < 40))
        Power_status = 'F';
    if(Power < 20)
        Power_status = 'G';

    //-----[走力判定]-----------------------------------------
    if(Run >= 90)
        Run_status = 'S';
    if((Run >= 80) && (Run < 90))
        Run_status = 'A';
    if((Run >= 70) && (Run < 80))
        Run_status = 'B';
    if((Run >= 60) && (Run < 70))
        Run_status = 'C';
    if((Run >= 50) && (Run < 60))
        Run_status = 'D';
    if((Run >= 40) && (Run < 50))
        Run_status = 'E';
    if((Run >= 20) && (Run < 40))
        Run_status = 'F';
    if(Run < 20)
        Run_status = 'G';

    //-----[肩力判定]-----------------------------------------
    if(Sholder >= 90)
        Sholder_status = 'S';
    if((Sholder >= 80) && (Sholder < 90))
        Sholder_status = 'A';
    if((Sholder >= 70) && (Sholder < 80))
        Sholder_status = 'B';
    if((Sholder >= 60) && (Sholder < 70))
        Sholder_status = 'C';
    if((Sholder >= 50) && (Sholder < 60))
        Sholder_status = 'D';
    if((Sholder >= 40) && (Sholder < 50))
        Sholder_status = 'E';
    if((Sholder >= 20) && (Sholder < 40))
        Sholder_status = 'F';
    if(Sholder < 20)
        Sholder_status = 'G';

    //-----[守備力判定]---------------------------------------
    if(Protect >= 90)
        Protect_status = 'S';
    if((Protect >= 80) && (Protect < 90))
        Protect_status = 'A';
    if((Protect >= 70) && (Protect < 80))
        Protect_status = 'B';
    if((Protect >= 60) && (Protect < 70))
        Protect_status = 'C';
    if((Protect >= 50) && (Protect < 60))
        Protect_status = 'D';
    if((Protect >= 40) && (Protect < 50))
        Protect_status = 'E';
    if((Protect >= 20) && (Protect < 40))
        Protect_status = 'F';
    if(Protect < 20)
        Protect_status = 'G';

    //-----[捕球判定]-----------------------------------------
    if(Catching >= 90)
        Catching_status = 'S';
    if((Catching >= 80) && (Catching < 90))
        Catching_status = 'A';
    if((Catching >= 70) && (Catching < 80))
        Catching_status = 'B';
    if((Catching >= 60) && (Catching < 70))
        Catching_status = 'C';
    if((Catching >= 50) && (Catching < 60))
        Catching_status = 'D';
    if((Catching >= 40) && (Catching < 50))
        Catching_status = 'E';
    if((Catching >= 20) && (Catching < 40))
        Catching_status = 'F';
    if(Catching < 20)
        Catching_status = 'G';
}

void Pitcher_Ball_decide(void) {
    //-----[球速判定]-----------------------------------
    int Ball_muscle, Ball_technique, Ball_spirit;
    int Ball_technique_length = 0, Ball_spirit_length = 0;

    if(Ball == 165)
        cout << "        [ 修得済み]        ";
    if(Ball == 164) {
        Ball_muscle = 69 * genius_point * ball_per;
        Ball_technique = 42 * genius_point * ball_per;
        Ball_spirit = 26 * genius_point * ball_per;
    }
    if(Ball == 163) {
        Ball_muscle = 68 * genius_point * ball_per;
        Ball_technique = 41 * genius_point * ball_per;
        Ball_spirit = 25 * genius_point * ball_per;
    }
    if(Ball == 162) {
        Ball_muscle = 67 * genius_point * ball_per;
        Ball_technique = 40 * genius_point * ball_per;
        Ball_spirit = 24 * genius_point * ball_per;
    }
    if(Ball == 161) {
        Ball_muscle = 66 * genius_point * ball_per;
        Ball_technique = 39 * genius_point * ball_per;
        Ball_spirit = 23 * genius_point * ball_per;
    }
    if(Ball == 160) {
        Ball_muscle = 65 * genius_point * ball_per;
        Ball_technique = 38 * genius_point * ball_per;
        Ball_spirit = 22 * genius_point * ball_per;
    }
    if(Ball == 159) {
        Ball_muscle = 64 * genius_point * ball_per;
        Ball_technique = 37 * genius_point * ball_per;
        Ball_spirit = 21 * genius_point * ball_per;
    }
    if(Ball == 158) {
        Ball_muscle = 63 * genius_point * ball_per;
        Ball_technique = 36 * genius_point * ball_per;
        Ball_spirit = 20 * genius_point * ball_per;
    }
    if(Ball == 157) {
        Ball_muscle = 62 * genius_point * ball_per;
        Ball_technique = 35 * genius_point * ball_per;
        Ball_spirit = 19 * genius_point * ball_per;
    }
    if(Ball == 156) {
        Ball_muscle = 61 * genius_point * ball_per;
        Ball_technique = 34 * genius_point * ball_per;
        Ball_spirit = 18 * genius_point * ball_per;
    }
    if(Ball == 155) {
        Ball_muscle = 60 * genius_point * ball_per;
        Ball_technique = 33 * genius_point * ball_per;
        Ball_spirit = 17 * genius_point * ball_per;
    }
    if(Ball == 154) {
        Ball_muscle = 59 * genius_point * ball_per;
        Ball_technique = 32 * genius_point * ball_per;
        Ball_spirit = 16 * genius_point * ball_per;
    }
    if(Ball == 153) {
        Ball_muscle = 58 * genius_point * ball_per;
        Ball_technique = 31 * genius_point * ball_per;
        Ball_spirit = 15 * genius_point * ball_per;
    }
    if(Ball == 152) {
        Ball_muscle = 57 * genius_point * ball_per;
        Ball_technique = 30 * genius_point * ball_per;
        Ball_spirit = 14 * genius_point * ball_per;
    }
    if(Ball == 151) {
        Ball_muscle = 56 * genius_point * ball_per;
        Ball_technique = 29 * genius_point * ball_per;
        Ball_spirit = 13 * genius_point * ball_per;
    }
    if(Ball == 150) {
        Ball_muscle = 55 * genius_point * ball_per;
        Ball_technique = 28 * genius_point * ball_per;
        Ball_spirit = 12 * genius_point * ball_per;
    }
    if(Ball == 149) {
        Ball_muscle = 49 * genius_point * ball_per;
        Ball_technique = 27 * genius_point * ball_per;
        Ball_spirit = 11 * genius_point * ball_per;
    }
    if(Ball == 148) {
        Ball_muscle = 48 * genius_point * ball_per;
        Ball_technique = 26 * genius_point * ball_per;
        Ball_spirit = 10 * genius_point * ball_per;
    }
    if(Ball == 147) {
        Ball_muscle = 47 * genius_point * ball_per;
        Ball_technique = 25 * genius_point * ball_per;
        Ball_spirit = 9 * genius_point * ball_per;
    }
    if(Ball == 146) {
        Ball_muscle = 46 * genius_point * ball_per;
        Ball_technique = 24 * genius_point * ball_per;
        Ball_spirit = 8 * genius_point * ball_per;
    }
    if(Ball == 145) {
        Ball_muscle = 45 * genius_point * ball_per;
        Ball_technique = 23 * genius_point * ball_per;
        Ball_spirit = 7 * genius_point * ball_per;
    }
    if(Ball == 144) {
        Ball_muscle = 39 * genius_point * ball_per;
        Ball_technique = 22 * genius_point * ball_per;
        Ball_spirit = 6 * genius_point * ball_per;
    }
    if(Ball == 143) {
        Ball_muscle = 38 * genius_point * ball_per;
        Ball_technique = 21 * genius_point * ball_per;
        Ball_spirit = 5 * genius_point * ball_per;
    }
    if(Ball == 142) {
        Ball_muscle = 37 * genius_point * ball_per;
        Ball_technique = 20 * genius_point * ball_per;
        Ball_spirit = 4 * genius_point * ball_per;
    }
    if(Ball == 141) {
        Ball_muscle = 36 * genius_point * ball_per;
        Ball_technique = 19 * genius_point * ball_per;
        Ball_spirit = 3 * genius_point * ball_per;
    }
    if(Ball == 140) {
        Ball_muscle = 35 * genius_point * ball_per;
        Ball_technique = 18 * genius_point * ball_per;
        Ball_spirit = 2 * genius_point * ball_per;
    }
    if((Ball > 134) && (Ball < 140)) {
        Ball_muscle = 26 * genius_point * ball_per;
        Ball_technique = 12 * genius_point * ball_per;
        Ball_spirit = 1;
    }
    if((Ball > 129) && (Ball < 135)) {
        Ball_muscle = 25 * genius_point * ball_per;
        Ball_technique = 11 * genius_point * ball_per;
        Ball_spirit = 1;
    }
    if((Ball > 119) && (Ball < 130)) {
        Ball_muscle = 24 * genius_point * ball_per;
        Ball_technique = 10 * genius_point * ball_per;
        Ball_spirit = 1;
    }
    if(Ball < 120) {
        Ball_muscle = 20 * genius_point;
        Ball_technique = 7 * genius_point;
        Ball_spirit = 1;
    }

    if(Ball_technique < 10)
        Ball_technique_length = 1;
    if(Ball_spirit < 10)
        Ball_spirit_length = 1;
    string Ball_technique_span(Ball_technique_length, ' ');
    string Ball_spirit_span(Ball_spirit_length, ' ');

    cout << "   " << Ball_muscle << " |   " << Ball_technique_span
         << Ball_technique << " |      |   " << Ball_spirit_span << Ball_spirit
         << " ";
}

void Pitcher_Control_decide(void) {
    //-----[コントロール判定]-----------------------------------
    int Control_technique, Control_spirit;
    int Control_technique_length = 0, Control_spirit_length = 0;

    if(Control == 100)
        cout << "       [ 修得済み]        ";
    if((Control >= 90) && (Control < 100)) {
        Control_technique = 26 * genius_point * control_per;
        Control_spirit = 16 * genius_point * control_per;
    }
    if((Control >= 80) && (Control < 90)) {
        Control_technique = 13 * genius_point * control_per;
        Control_spirit = 8 * genius_point * control_per;
    }
    if((Control >= 70) && (Control < 80)) {
        Control_technique = 12 * genius_point * control_per;
        Control_spirit = 8 * genius_point * control_per;
    }
    if((Control >= 60) && (Control < 70)) {
        Control_technique = 11 * genius_point * control_per;
        Control_spirit = 8 * genius_point * control_per;
    }
    if((Control >= 50) && (Control < 60)) {
        Control_technique = 10 * genius_point * control_per;
        Control_spirit = 7 * genius_point * control_per;
    }
    if((Control >= 40) && (Control < 50)) {
        Control_technique = 9 * genius_point * control_per;
        Control_spirit = 7 * genius_point * control_per;
    }
    if((Control >= 20) && (Control < 40)) {
        Control_technique = 8 * genius_point * control_per;
        Control_spirit = 6 * genius_point * control_per;
    }
    if(Control < 20) {
        Control_technique = 7 * genius_point * control_per;
        Control_spirit = 5 * genius_point * control_per;
    }

    if(Control_technique < 10)
        Control_technique_length = 1;
    if(Control_spirit < 10)
        Control_spirit_length = 1;
    string Control_technique_span(Control_technique_length, ' ');
    string Control_spirit_span(Control_spirit_length, ' ');

    cout << "      |   " << Control_technique_span << Control_technique
         << " |      |   " << Control_spirit_span << Control_spirit << " ";
}

void Pitcher_Stamina_decide(void) {
    //-----[スタミナ判定]-----------------------------------------
    int Stamina_muscle, Stamina_spirit;
    int Stamina_muscle_length = 0;

    if(Stamina == 100)
        cout << "       [ 修得済み]        ";
    if((Stamina >= 90) && (Stamina < 100)) {
        Stamina_muscle = 10 * genius_point * stamina_per;
        Stamina_spirit = 7 * genius_point * stamina_per;
    }
    if((Stamina >= 80) && (Stamina < 90)) {
        Stamina_muscle = 9 * genius_point * stamina_per;
        Stamina_spirit = 6 * genius_point * stamina_per;
    }
    if((Stamina >= 70) && (Stamina < 80)) {
        Stamina_muscle = 9 * genius_point * stamina_per;
        Stamina_spirit = 6 * genius_point * stamina_per;
    }
    if((Stamina >= 60) && (Stamina < 70)) {
        Stamina_muscle = 8 * genius_point * stamina_per;
        Stamina_spirit = 5 * genius_point * stamina_per;
    }
    if((Stamina >= 50) && (Stamina < 60)) {
        Stamina_muscle = 8 * genius_point * stamina_per;
        Stamina_spirit = 5 * genius_point * stamina_per;
    }
    if((Stamina >= 40) && (Stamina < 50)) {
        Stamina_muscle = 8 * genius_point * stamina_per;
        Stamina_spirit = 4 * genius_point * stamina_per;
    }
    if((Stamina >= 20) && (Stamina < 40)) {
        Stamina_muscle = 7 * genius_point * stamina_per;
        Stamina_spirit = 4 * genius_point * stamina_per;
    }
    if(Stamina < 20) {
        Stamina_muscle = 7 * genius_point * stamina_per;
        Stamina_spirit = 3 * genius_point * stamina_per;
    }

    if(Stamina_muscle < 10)
        Stamina_muscle_length = 1;
    string Stamina_muscle_span(Stamina_muscle_length, ' ');

    cout << "   " << Stamina_muscle_span << Stamina_muscle
         << " |      |      |    " << Stamina_spirit << " ";
}

void Pitcher_Slider_decide(void) {
    //-----[スライダー判定]-----------------------------------------
    int Slider_technique, Slider_evolving, Slider_spirit;
    int Slider_technique_length = 0, Slider_evolving_length = 0;

    if(Slider == 7)
        cout << "       [ 修得済み]        ";
    if(Slider == 6) {
        Slider_technique = 26 * genius_point * evolving_per;
        Slider_evolving = 132 * genius_point * evolving_per;
        Slider_spirit = 5 * genius_point * evolving_per;
    }
    if(Slider == 5) {
        Slider_technique = 22 * genius_point * evolving_per;
        Slider_evolving = 117 * genius_point * evolving_per;
        Slider_spirit = 4 * genius_point * evolving_per;
    }
    if(Slider == 4) {
        Slider_technique = 19 * genius_point * evolving_per;
        Slider_evolving = 102 * genius_point * evolving_per;
        Slider_spirit = 4 * genius_point * evolving_per;
    }
    if(Slider == 3) {
        Slider_technique = 16 * genius_point * evolving_per;
        Slider_evolving = 58 * genius_point * evolving_per;
        Slider_spirit = 3 * genius_point * evolving_per;
    }
    if(Slider == 2) {
        Slider_technique = 13 * genius_point * evolving_per;
        Slider_evolving = 48 * genius_point * evolving_per;
        Slider_spirit = 3 * genius_point * evolving_per;
    }
    if(Slider == 1) {
        Slider_technique = 9 * genius_point * evolving_per;
        Slider_evolving = 38 * genius_point * evolving_per;
        Slider_spirit = 2 * genius_point * evolving_per;
    }
    if(Slider == 0) {
        Slider_technique = 5 * genius_point * evolving_per;
        Slider_evolving = 28 * genius_point * evolving_per;
        Slider_spirit = 1;
    }

    if(Slider_technique < 10)
        Slider_technique_length = 1;
    if(Slider_evolving < 100)
        Slider_evolving_length = 1;
    string Slider_technique_span(Slider_technique_length, ' ');
    string Slider_evolving_span(Slider_evolving_length, ' ');

    cout << "      |   " << Slider_technique_span << Slider_technique << " |  "
         << Slider_evolving_span << Slider_evolving << " |    " << Slider_spirit
         << " ";
}

void Pitcher_Curve_decide(void) {
    //-----[カーブ判定]-----------------------------------------
    int Curve_technique, Curve_evolving, Curve_spirit;
    int Curve_technique_length = 0, Curve_evolving_length = 0;

    if(Curve == 7)
        cout << "       [ 修得済み]        ";
    if(Curve == 6) {
        Curve_technique = 26 * genius_point * evolving_per;
        Curve_evolving = 132 * genius_point * evolving_per;
        Curve_spirit = 5 * genius_point * evolving_per;
    }
    if(Curve == 5) {
        Curve_technique = 22 * genius_point * evolving_per;
        Curve_evolving = 117 * genius_point * evolving_per;
        Curve_spirit = 4 * genius_point * evolving_per;
    }
    if(Curve == 4) {
        Curve_technique = 19 * genius_point * evolving_per;
        Curve_evolving = 102 * genius_point * evolving_per;
        Curve_spirit = 4 * genius_point * evolving_per;
    }
    if(Curve == 3) {
        Curve_technique = 16 * genius_point * evolving_per;
        Curve_evolving = 58 * genius_point * evolving_per;
        Curve_spirit = 3 * genius_point * evolving_per;
    }
    if(Curve == 2) {
        Curve_technique = 13 * genius_point * evolving_per;
        Curve_evolving = 48 * genius_point * evolving_per;
        Curve_spirit = 3 * genius_point * evolving_per;
    }
    if(Curve == 1) {
        Curve_technique = 9 * genius_point * evolving_per;
        Curve_evolving = 38 * genius_point * evolving_per;
        Curve_spirit = 2 * genius_point * evolving_per;
    }
    if(Curve == 0) {
        Curve_technique = 5 * genius_point * evolving_per;
        Curve_evolving = 28 * genius_point * evolving_per;
        Curve_spirit = 1;
    }

    if(Curve_technique < 10)
        Curve_technique_length = 1;
    if(Curve_evolving < 100)
        Curve_evolving_length = 1;
    string Curve_technique_span(Curve_technique_length, ' ');
    string Curve_evolving_span(Curve_evolving_length, ' ');

    cout << "      |   " << Curve_technique_span << Curve_technique << " |  "
         << Curve_evolving_span << Curve_evolving << " |    " << Curve_spirit
         << " ";
}

void Pitcher_Fork_decide(void) {
    //-----[フォーク判定]-----------------------------------------
    int Fork_technique, Fork_evolving, Fork_spirit;
    int Fork_technique_length = 0, Fork_evolving_length = 0;

    if(Fork == 7)
        cout << "       [ 修得済み]        ";
    if(Fork == 6) {
        Fork_technique = 26 * genius_point * evolving_per;
        Fork_evolving = 132 * genius_point * evolving_per;
        Fork_spirit = 5 * genius_point * evolving_per;
    }
    if(Fork == 5) {
        Fork_technique = 22 * genius_point * evolving_per;
        Fork_evolving = 117 * genius_point * evolving_per;
        Fork_spirit = 4 * genius_point * evolving_per;
    }
    if(Fork == 4) {
        Fork_technique = 19 * genius_point * evolving_per;
        Fork_evolving = 102 * genius_point * evolving_per;
        Fork_spirit = 4 * genius_point * evolving_per;
    }
    if(Fork == 3) {
        Fork_technique = 16 * genius_point * evolving_per;
        Fork_evolving = 58 * genius_point * evolving_per;
        Fork_spirit = 3 * genius_point * evolving_per;
    }
    if(Fork == 2) {
        Fork_technique = 13 * genius_point * evolving_per;
        Fork_evolving = 48 * genius_point * evolving_per;
        Fork_spirit = 3 * genius_point * evolving_per;
    }
    if(Fork == 1) {
        Fork_technique = 9 * genius_point * evolving_per;
        Fork_evolving = 38 * genius_point * evolving_per;
        Fork_spirit = 2 * genius_point * evolving_per;
    }
    if(Fork == 0) {
        Fork_technique = 5 * genius_point * evolving_per;
        Fork_evolving = 28 * genius_point * evolving_per;
        Fork_spirit = 1;
    }

    if(Fork_technique < 10)
        Fork_technique_length = 1;
    if(Fork_evolving < 100)
        Fork_evolving_length = 1;
    string Fork_technique_span(Fork_technique_length, ' ');
    string Fork_evolving_span(Fork_evolving_length, ' ');

    cout << "      |   " << Fork_technique_span << Fork_technique << " |  "
         << Fork_evolving_span << Fork_evolving << " |    " << Fork_spirit
         << " ";
}

void Pitcher_Sinker_decide(void) {
    //-----[シンカー判定]-----------------------------------------
    int Sinker_technique, Sinker_evolving, Sinker_spirit;
    int Sinker_technique_length = 0, Sinker_evolving_length = 0;

    if(Sinker == 7)
        cout << "       [ 修得済み]        ";
    if(Sinker == 6) {
        Sinker_technique = 26 * genius_point * evolving_per;
        Sinker_evolving = 132 * genius_point * evolving_per;
        Sinker_spirit = 5 * genius_point * evolving_per;
    }
    if(Sinker == 5) {
        Sinker_technique = 22 * genius_point * evolving_per;
        Sinker_evolving = 117 * genius_point * evolving_per;
        Sinker_spirit = 4 * genius_point * evolving_per;
    }
    if(Sinker == 4) {
        Sinker_technique = 19 * genius_point * evolving_per;
        Sinker_evolving = 102 * genius_point * evolving_per;
        Sinker_spirit = 4 * genius_point * evolving_per;
    }
    if(Sinker == 3) {
        Sinker_technique = 16 * genius_point * evolving_per;
        Sinker_evolving = 58 * genius_point * evolving_per;
        Sinker_spirit = 3 * genius_point * evolving_per;
    }
    if(Sinker == 2) {
        Sinker_technique = 13 * genius_point * evolving_per;
        Sinker_evolving = 48 * genius_point * evolving_per;
        Sinker_spirit = 3 * genius_point * evolving_per;
    }
    if(Sinker == 1) {
        Sinker_technique = 9 * genius_point * evolving_per;
        Sinker_evolving = 38 * genius_point * evolving_per;
        Sinker_spirit = 2 * genius_point * evolving_per;
    }
    if(Sinker == 0) {
        Sinker_technique = 5 * genius_point * evolving_per;
        Sinker_evolving = 28 * genius_point * evolving_per;
        Sinker_spirit = 1;
    }

    if(Sinker_technique < 10)
        Sinker_technique_length = 1;
    if(Sinker_evolving < 100)
        Sinker_evolving_length = 1;
    string Sinker_technique_span(Sinker_technique_length, ' ');
    string Sinker_evolving_span(Sinker_evolving_length, ' ');

    cout << "      |   " << Sinker_technique_span << Sinker_technique << " |  "
         << Sinker_evolving_span << Sinker_evolving << " |    " << Sinker_spirit
         << " ";
}

void Pitcher_Shoot_decide(void) {
    //-----[シュート判定]-----------------------------------------
    int Shoot_technique, Shoot_evolving, Shoot_spirit;
    int Shoot_technique_length = 0, Shoot_evolving_length = 0;

    if(Shoot == 7)
        cout << "       [ 修得済み]        ";
    if(Shoot == 6) {
        Shoot_technique = 26 * genius_point * evolving_per;
        Shoot_evolving = 132 * genius_point * evolving_per;
        Shoot_spirit = 5 * genius_point * evolving_per;
    }
    if(Shoot == 5) {
        Shoot_technique = 22 * genius_point * evolving_per;
        Shoot_evolving = 117 * genius_point * evolving_per;
        Shoot_spirit = 4 * genius_point * evolving_per;
    }
    if(Shoot == 4) {
        Shoot_technique = 19 * genius_point * evolving_per;
        Shoot_evolving = 102 * genius_point * evolving_per;
        Shoot_spirit = 4 * genius_point * evolving_per;
    }
    if(Shoot == 3) {
        Shoot_technique = 16 * genius_point * evolving_per;
        Shoot_evolving = 58 * genius_point * evolving_per;
        Shoot_spirit = 3 * genius_point * evolving_per;
    }
    if(Shoot == 2) {
        Shoot_technique = 13 * genius_point * evolving_per;
        Shoot_evolving = 48 * genius_point * evolving_per;
        Shoot_spirit = 3 * genius_point * evolving_per;
    }
    if(Shoot == 1) {
        Shoot_technique = 9 * genius_point * evolving_per;
        Shoot_evolving = 38 * genius_point * evolving_per;
        Shoot_spirit = 2 * genius_point * evolving_per;
    }
    if(Shoot == 0) {
        Shoot_technique = 5 * genius_point * evolving_per;
        Shoot_evolving = 28 * genius_point * evolving_per;
        Shoot_spirit = 1;
    }

    if(Shoot_technique < 10)
        Shoot_technique_length = 1;
    if(Shoot_evolving < 100)
        Shoot_evolving_length = 1;
    string Shoot_technique_span(Shoot_technique_length, ' ');
    string Shoot_evolving_span(Shoot_evolving_length, ' ');

    cout << "      |   " << Shoot_technique_span << Shoot_technique << " |  "
         << Shoot_evolving_span << Shoot_evolving << " |    " << Shoot_spirit
         << " ";
}

void Batter_Trajectory_decide(void) {
    // int Trajectory_point, Meet_point, Power_point, Run_point, Sholder_point,
    // Protect_point, Catching_point;
    //-----[弾道判定]-------------------------------------------
    int Trajectory_muscle, Trajectory_technique, Trajectory_spirit;
    int Trajectory_muscle_length = 0, Trajectory_technique_length = 0,
        Trajectory_spirit_length = 0;

    if(Trajectory == 4)
        cout << "       [ 修得済み]         ";
    if(Trajectory == 3) {
        Trajectory_muscle = 50 * genius_point;
        Trajectory_technique = 50 * genius_point;
        Trajectory_spirit = 50 * genius_point;
    }
    if(Trajectory == 2) {
        Trajectory_muscle = 30 * genius_point;
        Trajectory_technique = 30 * genius_point;
        Trajectory_spirit = 30 * genius_point;
    }
    if(Trajectory == 1) {
        Trajectory_muscle = 10 * genius_point;
        Trajectory_technique = 10 * genius_point;
        Trajectory_spirit = 10 * genius_point;
    }

    if(Trajectory_muscle < 10)
        Trajectory_muscle_length = 1;
    if(Trajectory_technique < 10)
        Trajectory_technique_length = 1;
    if(Trajectory_spirit < 10)
        Trajectory_spirit_length = 1;
    string Trajectory_muscle_span(Trajectory_muscle_length, ' ');
    string Trajectory_technique_span(Trajectory_technique_length, ' ');
    string Trajectory_spirit_span(Trajectory_spirit_length, ' ');

    cout << "   " << Trajectory_muscle_span << Trajectory_muscle
         << " |      |   " << Trajectory_technique_span << Trajectory_technique
         << " |   " << Trajectory_spirit_span << Trajectory_spirit << " ";
}

void Batter_Meet_decide(void) {
    //-----[ミート判定]-----------------------------------
    int Meet_muscle, Meet_technique, Meet_spirit;
    int Meet_technique_length = 0, Meet_spirit_length = 0;

    if(Meet == 100)
        cout << "       [ 修得済み]        ";
    if((Meet >= 90) && (Meet < 100)) {
        Meet_muscle = 5 * genius_point * meet_per;
        Meet_technique = 18 * genius_point * meet_per;
        Meet_spirit = 14 * genius_point * meet_per;
    }
    if((Meet >= 80) && (Meet < 90)) {
        Meet_muscle = 4 * genius_point * meet_per;
        Meet_technique = 17 * genius_point * meet_per;
        Meet_spirit = 13 * genius_point * meet_per;
    }
    if((Meet >= 70) && (Meet < 80)) {
        Meet_muscle = 4 * genius_point * meet_per;
        Meet_technique = 16 * genius_point * meet_per;
        Meet_spirit = 12 * genius_point * meet_per;
    }
    if((Meet >= 60) && (Meet < 70)) {
        Meet_muscle = 3 * genius_point * meet_per;
        Meet_technique = 14 * genius_point * meet_per;
        Meet_spirit = 11 * genius_point * meet_per;
    }
    if((Meet >= 50) && (Meet < 60)) {
        Meet_muscle = 3 * genius_point * meet_per;
        Meet_technique = 12 * genius_point * meet_per;
        Meet_spirit = 9 * genius_point * meet_per;
    }
    if((Meet >= 40) && (Meet < 50)) {
        Meet_muscle = 2 * genius_point * meet_per;
        Meet_technique = 10 * genius_point * meet_per;
        Meet_spirit = 8 * genius_point * meet_per;
    }
    if((Meet >= 20) && (Meet < 40)) {
        Meet_muscle = 2 * genius_point * meet_per;
        Meet_technique = 8 * genius_point * meet_per;
        Meet_spirit = 6 * genius_point * meet_per;
    }
    if(Meet < 20) {
        Meet_muscle = 1;
        Meet_technique = 6 * genius_point * meet_per;
        Meet_spirit = 4 * genius_point * meet_per;
    }

    if(Meet_technique < 10)
        Meet_technique_length = 1;
    if(Meet_spirit < 10)
        Meet_spirit_length = 1;
    string Meet_technique_span(Meet_technique_length, ' ');
    string Meet_spirit_span(Meet_spirit_length, ' ');

    cout << "    " << Meet_muscle << " |      |   " << Meet_technique_span
         << Meet_technique << " |   " << Meet_spirit_span << Meet_spirit << " ";
}

void Batter_Power_decide(void) {
    //-----[パワー判定]---------------------------------------
    int Power_muscle, Power_technique;
    int Power_muscle_length = 0, Power_technique_length = 0;

    if(Power == 100)
        cout << "       [ 修得済み]        ";
    if((Power >= 90) && (Power < 100)) {
        Power_muscle = 30 * genius_point * power_per;
        Power_technique = 10 * genius_point * power_per;
    }
    if((Power >= 80) && (Power < 90)) {
        Power_muscle = 27 * genius_point * power_per;
        Power_technique = 9 * genius_point * power_per;
    }
    if((Power >= 70) && (Power < 80)) {
        Power_muscle = 24 * genius_point * power_per;
        Power_technique = 8 * genius_point * power_per;
    }
    if((Power >= 60) && (Power < 70)) {
        Power_muscle = 21 * genius_point * power_per;
        Power_technique = 7 * genius_point * power_per;
    }
    if((Power >= 50) && (Power < 60)) {
        Power_muscle = 18 * genius_point * power_per;
        Power_technique = 6 * genius_point * power_per;
    }
    if((Power >= 40) && (Power < 50)) {
        Power_muscle = 15 * genius_point * power_per;
        Power_technique = 5 * genius_point * power_per;
    }
    if((Power >= 20) && (Power < 40)) {
        Power_muscle = 12 * genius_point * power_per;
        Power_technique = 4 * genius_point * power_per;
    }
    if(Power < 20) {
        Power_muscle = 10 * genius_point * power_per;
        Power_technique = 2 * genius_point * power_per;
    }

    if(Power_muscle < 10)
        Power_muscle_length = 1;
    if(Power_technique < 10)
        Power_technique_length = 1;
    string Power_muscle_span(Power_muscle_length, ' ');
    string Power_technique_span(Power_technique_length, ' ');

    cout << "   " << Power_muscle_span << Power_muscle << " |      |   "
         << Power_technique_span << Power_technique << " |      ";
}

void Batter_Run_decide(void) {
    //-----[走力判定]-----------------------------------------
    int Run_muscle, Run_agile;
    int Run_muscle_length = 0, Run_agile_length = 0;

    if(Run == 100)
        cout << "       [ 修得済み]        ";
    if((Run >= 90) && (Run < 100)) {
        Run_muscle = 5 * genius_point * run_per;
        Run_agile = 20 * genius_point * run_per;
    }
    if((Run >= 80) && (Run < 90)) {
        Run_muscle = 4 * genius_point * run_per;
        Run_agile = 20 * genius_point * run_per;
    }
    if((Run >= 70) && (Run < 80)) {
        Run_muscle = 4 * genius_point * run_per;
        Run_agile = 18 * genius_point * run_per;
    }
    if((Run >= 60) && (Run < 70)) {
        Run_muscle = 3 * genius_point * run_per;
        Run_agile = 16 * genius_point * run_per;
    }
    if((Run >= 50) && (Run < 60)) {
        Run_muscle = 3 * genius_point * run_per;
        Run_agile = 14 * genius_point * run_per;
    }
    if((Run >= 40) && (Run < 50)) {
        Run_muscle = 2 * genius_point * run_per;
        Run_agile = 12 * genius_point * run_per;
    }
    if((Run >= 20) && (Run < 40)) {
        Run_muscle = 2 * genius_point * run_per;
        Run_agile = 10 * genius_point * run_per;
    }
    if(Run < 20) {
        Run_muscle = 1;
        Run_agile = 8 * genius_point * run_per;
    }

    if(Run_muscle < 10)
        Run_muscle_length = 1;
    if(Run_agile < 10)
        Run_agile_length = 1;
    string Run_muscle_span(Run_muscle_length, ' ');
    string Run_agile_span(Run_agile_length, ' ');

    cout << "   " << Run_muscle_span << Run_muscle << " |   " << Run_agile_span
         << Run_agile << " |      |      ";
}

void Batter_Sholder_decide(void) {
    //-----[肩力判定]-----------------------------------------
    int Sholder_muscle, Sholder_agile, Sholder_technique;

    if(Sholder == 100)
        cout << "       [ 修得済み]        ";
    if((Sholder >= 90) && (Sholder < 100)) {
        Sholder_muscle = 9 * genius_point * sholder_per;
        Sholder_agile = 9 * genius_point * sholder_per;
        Sholder_technique = 9 * genius_point * sholder_per;
    }
    if((Sholder >= 80) && (Sholder < 90)) {
        Sholder_muscle = 9 * genius_point * sholder_per;
        Sholder_agile = 9 * genius_point * sholder_per;
        Sholder_technique = 9 * genius_point * sholder_per;
    }
    if((Sholder >= 70) && (Sholder < 80)) {
        Sholder_muscle = 8 * genius_point * sholder_per;
        Sholder_agile = 8 * genius_point * sholder_per;
        Sholder_technique = 8 * genius_point * sholder_per;
    }
    if((Sholder >= 60) && (Sholder < 70)) {
        Sholder_muscle = 7 * genius_point * sholder_per;
        Sholder_agile = 7 * genius_point * sholder_per;
        Sholder_technique = 7 * genius_point * sholder_per;
    }
    if((Sholder >= 50) && (Sholder < 60)) {
        Sholder_muscle = 6 * genius_point * sholder_per;
        Sholder_agile = 6 * genius_point * sholder_per;
        Sholder_technique = 6 * genius_point * sholder_per;
    }
    if((Sholder >= 40) && (Sholder < 50)) {
        Sholder_muscle = 5 * genius_point * sholder_per;
        Sholder_agile = 5 * genius_point * sholder_per;
        Sholder_technique = 5 * genius_point * sholder_per;
    }
    if((Sholder >= 20) && (Sholder < 40)) {
        Sholder_muscle = 4 * genius_point * sholder_per;
        Sholder_agile = 4 * genius_point * sholder_per;
        Sholder_technique = 4 * genius_point * sholder_per;
    }
    if(Sholder < 20) {
        Sholder_muscle = 3 * genius_point * sholder_per;
        Sholder_agile = 3 * genius_point * sholder_per;
        Sholder_technique = 3 * genius_point * sholder_per;
    }

    cout << "    " << Sholder_muscle << " |    " << Sholder_agile << " |    "
         << Sholder_technique << " |      ";
}

void Batter_Protect_decide(void) {
    //-----[守備力判定]-----------------------------------------
    int Protect_agile, Protect_technique, Protect_spirit;

    if(Protect == 100)
        cout << "       [ 修得済み]        ";
    if((Protect >= 90) && (Protect < 100)) {
        Protect_agile = 9 * genius_point * protect_per;
        Protect_technique = 9 * genius_point * protect_per;
        Protect_spirit = 9 * genius_point * protect_per;
    }
    if((Protect >= 80) && (Protect < 90)) {
        Protect_agile = 9 * genius_point * protect_per;
        Protect_technique = 9 * genius_point * protect_per;
        Protect_spirit = 9 * genius_point * protect_per;
    }
    if((Protect >= 70) && (Protect < 80)) {
        Protect_agile = 8 * genius_point * protect_per;
        Protect_technique = 8 * genius_point * protect_per;
        Protect_spirit = 8 * genius_point * protect_per;
    }
    if((Protect >= 60) && (Protect < 70)) {
        Protect_agile = 7 * genius_point * protect_per;
        Protect_technique = 7 * genius_point * protect_per;
        Protect_spirit = 7 * genius_point * protect_per;
    }
    if((Protect >= 50) && (Protect < 60)) {
        Protect_agile = 6 * genius_point * protect_per;
        Protect_technique = 6 * genius_point * protect_per;
        Protect_spirit = 6 * genius_point * protect_per;
    }
    if((Protect >= 40) && (Protect < 50)) {
        Protect_agile = 5 * genius_point * protect_per;
        Protect_technique = 5 * genius_point * protect_per;
        Protect_spirit = 5 * genius_point * protect_per;
    }
    if((Protect >= 20) && (Protect < 40)) {
        Protect_agile = 4 * genius_point * protect_per;
        Protect_technique = 4 * genius_point * protect_per;
        Protect_spirit = 4 * genius_point * protect_per;
    }
    if(Protect < 20) {
        Protect_agile = 3 * genius_point * protect_per;
        Protect_technique = 3 * genius_point * protect_per;
        Protect_spirit = 3 * genius_point * protect_per;
    }

    cout << "      |    " << Protect_agile << " |    " << Protect_technique
         << " |    " << Protect_spirit << " ";
}

void Batter_Catching_decide(void) {
    //-----[捕球判定]-----------------------------------------
    int Catching_agile, Catching_spirit;
    int Catching_spirit_length = 0;

    if(Catching == 100)
        cout << "       [ 修得済み]        ";
    if((Catching >= 90) && (Catching < 100)) {
        Catching_agile = 5 * genius_point * catching_per;
        Catching_spirit = 12 * genius_point * catching_per;
    }
    if((Catching >= 80) && (Catching < 90)) {
        Catching_agile = 5 * genius_point * catching_per;
        Catching_spirit = 11 * genius_point * catching_per;
    }
    if((Catching >= 70) && (Catching < 80)) {
        Catching_agile = 4 * genius_point * catching_per;
        Catching_spirit = 10 * genius_point * catching_per;
    }
    if((Catching >= 60) && (Catching < 70)) {
        Catching_agile = 4 * genius_point * catching_per;
        Catching_spirit = 9 * genius_point * catching_per;
    }
    if((Catching >= 50) && (Catching < 60)) {
        Catching_agile = 3 * genius_point * catching_per;
        Catching_spirit = 8 * genius_point * catching_per;
    }
    if((Catching >= 40) && (Catching < 50)) {
        Catching_agile = 3 * genius_point * catching_per;
        Catching_spirit = 7 * genius_point * catching_per;
    }
    if((Catching >= 20) && (Catching < 40)) {
        Catching_agile = 2 * genius_point * catching_per;
        Catching_spirit = 6 * genius_point * catching_per;
    }
    if(Catching < 20) {
        Catching_agile = 2 * genius_point * catching_per;
        Catching_spirit = 5 * genius_point * catching_per;
    }

    if(Catching_spirit < 10)
        Catching_spirit_length = 1;
    string Catching_spirit_span(Catching_spirit_length, ' ');

    cout << "      |    " << Catching_agile << " |      |   "
         << Catching_spirit_span << Catching_spirit << " ";
}

void Prolog(void) {
    if(getchar() == '\n') {
        system("clear");
        cout << "[監督]:「ぽきたw磨材ンゴ！？ありえん良さみが深いw」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_normal();
        cout << "[" << Name << "]:「監督！？」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        cout << "[監督]:「二郎からのセイクで優勝せえへん？」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_sad();
        cout << "[" << Name << "]:「それ、甲子園なのでは...」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        cout << "[監督]:「そり！そりすぎてソリになったw」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_sad();
        cout << "[" << Name << "]:「えぇ、、」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        cout << "[監督]:「や、漏れのモタクと化したことのNASA」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_sad();
        cout << "[" << Name << "]:「...。」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        cout << "[監督]:「そりでわ、無限に練りをしまつ。ぽやしみ〜」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_normal();
        cout << "[" << Name
             << "]:「やっと行ってくれた...。監督たまに変になるから困る。」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_angry();
        cout << "[" << Name << "]:「よし！甲子園目指して頑張るぞ！」▼ ";
        if(getchar() == '\n')
            cout << endl;
    }
}

void Control_color(char Control_status) {
    if(Control_status == 'S')
        cout << "\x1b[37m" << Control_status << "\x1b[39m";
    if(Control_status == 'A')
        cout << "\x1b[35m" << Control_status << "\x1b[39m";
    if(Control_status == 'B')
        cout << "\x1b[31m" << Control_status << "\x1b[39m";
    if(Control_status == 'C')
        cout << "\x1b[33m" << Control_status << "\x1b[39m";
    if(Control_status == 'D')
        cout << "\x1b[33m" << Control_status << "\x1b[39m";
    if(Control_status == 'E')
        cout << "\x1b[32m" << Control_status << "\x1b[39m";
    if(Control_status == 'F')
        cout << "\x1b[36m" << Control_status << "\x1b[39m";
    if(Control_status == 'G')
        cout << "\x1b[39m" << Control_status << "\x1b[39m";
}
void Stamina_color(char Stamina_status) {
    if(Stamina_status == 'S')
        cout << "\x1b[37m" << Stamina_status << "\x1b[39m";
    if(Stamina_status == 'A')
        cout << "\x1b[35m" << Stamina_status << "\x1b[39m";
    if(Stamina_status == 'B')
        cout << "\x1b[31m" << Stamina_status << "\x1b[39m";
    if(Stamina_status == 'C')
        cout << "\x1b[33m" << Stamina_status << "\x1b[39m";
    if(Stamina_status == 'D')
        cout << "\x1b[33m" << Stamina_status << "\x1b[39m";
    if(Stamina_status == 'E')
        cout << "\x1b[32m" << Stamina_status << "\x1b[39m";
    if(Stamina_status == 'F')
        cout << "\x1b[36m" << Stamina_status << "\x1b[39m";
    if(Stamina_status == 'G')
        cout << "\x1b[39m" << Stamina_status << "\x1b[39m";
}
void Trajectory_color(char Trajectory_status) {
    if(Trajectory_status == '4')
        cout << "\x1b[35m"
             << "↑"
             << "\x1b[39m";
    if(Trajectory_status == '3')
        cout << "\x1b[31m"
             << "↗"
             << "\x1b[39m";
    if(Trajectory_status == '2')
        cout << "\x1b[33m"
             << "↗︎"
             << "\x1b[39m";
    if(Trajectory_status == '1')
        cout << "\x1b[39m"
             << "→"
             << "\x1b[39m";
}
void Meet_color(char Meet_status) {
    if(Meet_status == 'S')
        cout << "\x1b[37m" << Meet_status << "\x1b[39m";
    if(Meet_status == 'A')
        cout << "\x1b[35m" << Meet_status << "\x1b[39m";
    if(Meet_status == 'B')
        cout << "\x1b[31m" << Meet_status << "\x1b[39m";
    if(Meet_status == 'C')
        cout << "\x1b[33m" << Meet_status << "\x1b[39m";
    if(Meet_status == 'D')
        cout << "\x1b[33m" << Meet_status << "\x1b[39m";
    if(Meet_status == 'E')
        cout << "\x1b[32m" << Meet_status << "\x1b[39m";
    if(Meet_status == 'F')
        cout << "\x1b[36m" << Meet_status << "\x1b[39m";
    if(Meet_status == 'G')
        cout << "\x1b[39m" << Meet_status << "\x1b[39m";
}
void Power_color(char Power_status) {
    if(Power_status == 'S')
        cout << "\x1b[37m" << Power_status << "\x1b[39m";
    if(Power_status == 'A')
        cout << "\x1b[35m" << Power_status << "\x1b[39m";
    if(Power_status == 'B')
        cout << "\x1b[31m" << Power_status << "\x1b[39m";
    if(Power_status == 'C')
        cout << "\x1b[33m" << Power_status << "\x1b[39m";
    if(Power_status == 'D')
        cout << "\x1b[33m" << Power_status << "\x1b[39m";
    if(Power_status == 'E')
        cout << "\x1b[32m" << Power_status << "\x1b[39m";
    if(Power_status == 'F')
        cout << "\x1b[36m" << Power_status << "\x1b[39m";
    if(Power_status == 'G')
        cout << "\x1b[39m" << Power_status << "\x1b[39m";
}
void Run_color(char Run_status) {
    if(Run_status == 'S')
        cout << "\x1b[37m" << Run_status << "\x1b[39m";
    if(Run_status == 'A')
        cout << "\x1b[35m" << Run_status << "\x1b[39m";
    if(Run_status == 'B')
        cout << "\x1b[31m" << Run_status << "\x1b[39m";
    if(Run_status == 'C')
        cout << "\x1b[33m" << Run_status << "\x1b[39m";
    if(Run_status == 'D')
        cout << "\x1b[33m" << Run_status << "\x1b[39m";
    if(Run_status == 'E')
        cout << "\x1b[32m" << Run_status << "\x1b[39m";
    if(Run_status == 'F')
        cout << "\x1b[36m" << Run_status << "\x1b[39m";
    if(Run_status == 'G')
        cout << "\x1b[39m" << Run_status << "\x1b[39m";
}
void Sholder_color(char Sholder_status) {
    if(Sholder_status == 'S')
        cout << "\x1b[37m" << Sholder_status << "\x1b[39m";
    if(Sholder_status == 'A')
        cout << "\x1b[35m" << Sholder_status << "\x1b[39m";
    if(Sholder_status == 'B')
        cout << "\x1b[31m" << Sholder_status << "\x1b[39m";
    if(Sholder_status == 'C')
        cout << "\x1b[33m" << Sholder_status << "\x1b[39m";
    if(Sholder_status == 'D')
        cout << "\x1b[33m" << Sholder_status << "\x1b[39m";
    if(Sholder_status == 'E')
        cout << "\x1b[32m" << Sholder_status << "\x1b[39m";
    if(Sholder_status == 'F')
        cout << "\x1b[36m" << Sholder_status << "\x1b[39m";
    if(Sholder_status == 'G')
        cout << "\x1b[39m" << Sholder_status << "\x1b[39m";
}
void Protect_color(char Protect_status) {
    if(Protect_status == 'S')
        cout << "\x1b[37m" << Protect_status << "\x1b[39m";
    if(Protect_status == 'A')
        cout << "\x1b[35m" << Protect_status << "\x1b[39m";
    if(Protect_status == 'B')
        cout << "\x1b[31m" << Protect_status << "\x1b[39m";
    if(Protect_status == 'C')
        cout << "\x1b[33m" << Protect_status << "\x1b[39m";
    if(Protect_status == 'D')
        cout << "\x1b[33m" << Protect_status << "\x1b[39m";
    if(Protect_status == 'E')
        cout << "\x1b[32m" << Protect_status << "\x1b[39m";
    if(Protect_status == 'F')
        cout << "\x1b[36m" << Protect_status << "\x1b[39m";
    if(Protect_status == 'G')
        cout << "\x1b[39m" << Protect_status << "\x1b[39m";
}
void Catching_color(char Catching_status) {
    if(Catching_status == 'S')
        cout << "\x1b[37m" << Catching_status << "\x1b[39m";
    if(Catching_status == 'A')
        cout << "\x1b[35m" << Catching_status << "\x1b[39m";
    if(Catching_status == 'B')
        cout << "\x1b[31m" << Catching_status << "\x1b[39m";
    if(Catching_status == 'C')
        cout << "\x1b[33m" << Catching_status << "\x1b[39m";
    if(Catching_status == 'D')
        cout << "\x1b[33m" << Catching_status << "\x1b[39m";
    if(Catching_status == 'E')
        cout << "\x1b[32m" << Catching_status << "\x1b[39m";
    if(Catching_status == 'F')
        cout << "\x1b[36m" << Catching_status << "\x1b[39m";
    if(Catching_status == 'G')
        cout << "\x1b[39m" << Catching_status << "\x1b[39m";
}

//スライダー関数
void Slider_1(int Slider_status) {
    if(Slider_status >= 1)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Slider_2(int Slider_status) {
    if(Slider_status >= 2)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Slider_3(int Slider_status) {
    if(Slider_status >= 3)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Slider_4(int Slider_status) {
    if(Slider_status >= 4)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Slider_5(int Slider_status) {
    if(Slider_status >= 5)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Slider_6(int Slider_status) {
    if(Slider_status >= 6)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Slider_7(int Slider_status) {
    if(Slider_status == 7)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}

//カーブ関数
void Curve_1(int Curve_status) {
    if(Curve_status >= 1)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Curve_2(int Curve_status) {
    if(Curve_status >= 2)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Curve_3(int Curve_status) {
    if(Curve_status >= 3)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Curve_4(int Curve_status) {
    if(Curve_status >= 4)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Curve_5(int Curve_status) {
    if(Curve_status >= 5)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Curve_6(int Curve_status) {
    if(Curve_status >= 6)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Curve_7(int Curve_status) {
    if(Curve_status == 7)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}

//フォーク関数
void Fork_1(int Fork_status) {
    if(Fork_status >= 1)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Fork_2(int Fork_status) {
    if(Fork_status >= 2)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Fork_3(int Fork_status) {
    if(Fork_status >= 3)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Fork_4(int Fork_status) {
    if(Fork_status >= 4)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Fork_5(int Fork_status) {
    if(Fork_status >= 5)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Fork_6(int Fork_status) {
    if(Fork_status >= 6)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Fork_7(int Fork_status) {
    if(Fork_status == 7)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}

//シンカー関数
void Sinker_1(int Sinker_status) {
    if(Sinker_status >= 1)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Sinker_2(int Sinker_status) {
    if(Sinker_status >= 2)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Sinker_3(int Sinker_status) {
    if(Sinker_status >= 3)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Sinker_4(int Sinker_status) {
    if(Sinker_status >= 4)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Sinker_5(int Sinker_status) {
    if(Sinker_status >= 5)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Sinker_6(int Sinker_status) {
    if(Sinker_status >= 6)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Sinker_7(int Sinker_status) {
    if(Sinker_status == 7)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}

//シュート関数
void Shoot_1(int Shoot_status) {
    if(Shoot_status >= 1)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Shoot_2(int Shoot_status) {
    if(Shoot_status >= 2)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Shoot_3(int Shoot_status) {
    if(Shoot_status >= 3)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Shoot_4(int Shoot_status) {
    if(Shoot_status >= 4)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Shoot_5(int Shoot_status) {
    if(Shoot_status >= 5)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Shoot_6(int Shoot_status) {
    if(Shoot_status >= 6)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}
void Shoot_7(int Shoot_status) {
    if(Shoot_status == 7)
        cout << "["
             << "\x1b[31m"
             << "*"
             << "\x1b[39m"
             << "]";
    else
        cout << "[ ]";
}

void Daijyoubu(void) {
    int i = 0; //改造選択肢
    if(getchar() == '\n') {
        system("clear");
        cout << "[？？？]:「ヨクイラッシャイマシタ！」";
    }
    if(getchar() == '\n') {
        system("clear");
        cout << "[？？？]:「オ待チシテイタノデース！」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_surprise();
        cout << "[" << Name << "]:「あなたは誰！？」▼ ";
    }

    if(getchar() == '\n') {
        system("clear");
        Daijyoubu_success();
        cout << "[？？？]:「ワタシノ名ハダイジョーブ博士デース！」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_normal();
        cout << "[" << Name << "]:「ダイジョーブ博士？」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Daijyoubu_success();
        cout << "[ダイジョーブ博士]:"
                "「ソウデース。アナタヲ改造スルタメニヤッテキタノデース。」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_sad();
        cout << "[" << Name
             << "]:「(なんかすごく怪しいけどちょっとやってみたいな。。。)」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Daijyoubu_success();
        cout << "[ダイジョーブ博士]:"
                "「シカシ、ソノタメニハ大キナ危険ヲ伴イマス。」▼ ";
    }
    if(getchar() == '\n') {
        system("clear");
        Daijyoubu_success();
        cout << "[ダイジョーブ博士]:「成功率モ高クアリマセン！」▼ ";
    }
DAIJYOUBU:
    if(getchar() == '\n') {
        system("clear");
        Pawapuro_normal();
        cout << "[" << Name << "]:「んーどうしよう...」▼ " << endl;
    }
    if(getchar() == '\n')
        cout << "[1]:強くなりたい     [2]:やめておく▼ " << endl;
    cout << "選択 -> ";
    cin >> i;
    if((i != 1) && (i != 2)) {
        system("clear");
        Daijyoubu_fail();
        cout << "[ダイジョーブ博士]:「ソンナ選択肢ハアリマセーン！」▼ ";
        if(getchar() == '\n')
            goto DAIJYOUBU;
    }
    if(i == 1) {
        if(getchar() == '\n') {
            system("clear");
            Daijyoubu_success();
            cout << "[ダイジョーブ博士]:「デハ治療ヲ始メマショウ.....」▼ ";
        }
        if(getchar() == '\n') {
            system("clear");
            Daijyoubu_success();
            cout << "[ダイジョーブ博士]:「ソノ野望ニ支払ウ代償ヲ」▼ ";
        }
        if(getchar() == '\n') {
            system("clear");
            cout << "(ビリビリビリッ) ▼ ";
        }
        if(getchar() == '\n') {
            system("clear");
            cout << "うぎゃああああああああっ！！！ ▼ ";
        }
        if(getchar() == '\n') {
            system("clear");
            Daijyoubu_success();
            cout << "オウ！奇跡デス！成功シタデース！ ▼ ";
        }
        if(getchar() == '\n') {
            system("clear");
            Pawapuro_surprise();
            cout << "[" << Name << "]:「ハッ！　ここは？」▼ ";
        }
        if(getchar() == '\n') {
            system("clear");
            Pawapuro_normal();
            cout << "[" << Name << "]:「何があったんだっけ？」▼ ";
        }
        if(getchar() == '\n') {
            system("clear");
            Pawapuro_normal();
            cout << "[" << Name << "]:「よく覚えてない...」▼ ";
        }
        if(getchar() == '\n') {
            system("clear");
            Pawapuro_happy();
            cout << "[" << Name << "]:「ま、いいか！」▼ ";
        }

        if(((rand() % 10 + 1) > 0) && ((rand() % 10 + 1) < DAIJYOUBU_2)) {
            if(Position == 1) { //投手の場合
                // MAX値より上にならないための変数
                int d_ball = 0, d_control = 0, d_stamina = 0;
                // MAX値と現能力値の差分
                d_ball = 165 - Ball;
                d_control = 100 - Control;
                d_stamina = 100 - Stamina;

                if(getchar() == '\n') {
                    system("clear");
                    Pawapuro_happy();
                    if(d_ball >= 5) {
                        Ball += 5;
                        cout << "\x1b[33m"
                             << "球速"
                             << "\x1b[34m"
                             << "が5上がった。 ▼ "
                             << "\x1b[39m";
                    } else if(d_ball > 0) {
                        Ball += d_ball;
                        cout << "\x1b[33m"
                             << "球速"
                             << "\x1b[34m"
                             << "が" << d_ball << "上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "球速はもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }
                if(getchar() == '\n') {
                    if(d_control >= 10) {
                        Control += 10;
                        cout << "\x1b[33m"
                             << "コントロール"
                             << "\x1b[34m"
                             << "が10上がった。 ▼ "
                             << "\x1b[39m";
                    } else if(d_control > 0) {
                        Control += d_control;
                        cout << "\x1b[33m"
                             << "コントロール"
                             << "\x1b[34m"
                             << "が" << d_control << "上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "コントロールはもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }
                if(getchar() == '\n') {
                    if(d_stamina >= 10) {
                        Stamina += 10;
                        cout << "\x1b[33m"
                             << "スタミナ"
                             << "\x1b[34m"
                             << "が10上がった。 ▼ "
                             << "\x1b[39m";
                    } else if(d_stamina > 0) {
                        Stamina += d_stamina;
                        cout << "\x1b[33m"
                             << "スタミナ"
                             << "\x1b[34m"
                             << "が" << d_stamina << "上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "スタミナはもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }
                //ダイジョーブ博士、スライダー関係
                if((Slider > 0) && (Slider < 7)) {
                    Slider += 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "スライダー"
                             << "\x1b[34m"
                             << "が1上がった。 ▼ "
                             << "\x1b[39m";
                } else if(Slider == 7) {
                    if(getchar() == '\n')
                        cout << "\x1b[31m"
                             << "スライダーはこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                } else {
                }
                //ダイジョーブ博士、カーブ関係
                if((Curve > 0) && (Curve < 7)) {
                    Curve += 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "カーブ"
                             << "\x1b[34m"
                             << "が1上がった。 ▼ "
                             << "\x1b[39m";
                } else if(Curve == 7) {
                    if(getchar() == '\n')
                        cout << "\x1b[31m"
                             << "カーブはこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                } else {
                }
                //ダイジョーブ博士、フォーク関係
                if((Fork > 0) && (Fork < 7)) {
                    Fork += 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "フォーク"
                             << "\x1b[34m"
                             << "が1上がった。 ▼ "
                             << "\x1b[39m";
                } else if(Fork == 7) {
                    if(getchar() == '\n')
                        cout << "\x1b[31m"
                             << "フォークはこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                } else {
                }
                //ダイジョーブ博士、シンカー関係
                if((Sinker > 0) && (Sinker < 7)) {
                    Sinker += 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "シンカー"
                             << "\x1b[34m"
                             << "が1上がった。 ▼ "
                             << "\x1b[39m";
                } else if(Sinker == 7) {
                    if(getchar() == '\n')
                        cout << "\x1b[31m"
                             << "シンカーはこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                } else {
                }
                //ダイジョーブ博士、シュート関係
                if((Shoot > 0) && (Shoot < 7)) {
                    Shoot += 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "シュート"
                             << "\x1b[34m"
                             << "が1上がった。 ▼ "
                             << "\x1b[39m";
                } else if(Shoot == 7) {
                    if(getchar() == '\n')
                        cout << "\x1b[31m"
                             << "シュートはこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                } else {
                }
                condition = 5; //調子が絶好調に
            }                  //成功if終了(投手)
            else {             //野手の場合
                // MAX値より上にならないための変数
                int d_meet = 0, d_power = 0, d_run = 0, d_sholder = 0,
                    d_protect = 0, d_catching = 0;
                // MAX値と現能力値の差分
                d_meet = 100 - Meet;
                d_power = 100 - Power;
                d_run = 100 - Run;
                d_sholder = 100 - Sholder;
                d_protect = 100 - Protect;
                d_catching = 100 - Catching;

                //ダイジョーブ博士、弾道関係
                if(getchar() == '\n') {
                    system("clear");
                    Pawapuro_happy();
                    if(Trajectory < 4) {
                        Trajectory++;
                        cout << "\x1b[33m"
                             << "弾道"
                             << "\x1b[34m"
                             << "が1上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "弾道はもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }

                //ダイジョーブ博士、ミート関係
                if(getchar() == '\n') {
                    if(d_meet >= 10) {
                        Meet += 10;
                        cout << "\x1b[33m"
                             << "ミート"
                             << "\x1b[34m"
                             << "が10上がった。 ▼ "
                             << "\x1b[39m";
                    } else if(d_meet > 0) {
                        Meet += d_meet;
                        cout << "\x1b[33m"
                             << "ミート"
                             << "\x1b[34m"
                             << "が" << d_meet << "上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "ミートはもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }

                //ダイジョーブ博士、パワー関係
                if(getchar() == '\n') {
                    if(d_power >= 10) {
                        Power += 10;
                        cout << "\x1b[33m"
                             << "パワー"
                             << "\x1b[34m"
                             << "が10上がった。 ▼ "
                             << "\x1b[39m";
                    } else if(d_power > 0) {
                        Power += d_power;
                        cout << "\x1b[33m"
                             << "パワー"
                             << "\x1b[34m"
                             << "が" << d_power << "上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "パワーはもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }

                //ダイジョーブ博士、走力関係
                if(getchar() == '\n') {
                    if(d_run >= 10) {
                        Run += 10;
                        cout << "\x1b[33m"
                             << "走力"
                             << "\x1b[34m"
                             << "が10上がった。 ▼ "
                             << "\x1b[39m";
                    } else if(d_run > 0) {
                        Run += d_run;
                        cout << "\x1b[33m"
                             << "走力"
                             << "\x1b[34m"
                             << "が" << d_run << "上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "走力はもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }

                //ダイジョーブ博士、肩力関係
                if(getchar() == '\n') {
                    if(d_sholder >= 10) {
                        Sholder += 10;
                        cout << "\x1b[33m"
                             << "肩力"
                             << "\x1b[34m"
                             << "が10上がった。 ▼ "
                             << "\x1b[39m";
                    } else if(d_sholder > 0) {
                        Sholder += d_sholder;
                        cout << "\x1b[33m"
                             << "肩力"
                             << "\x1b[34m"
                             << "が" << d_sholder << "上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "肩力はもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }

                //ダイジョーブ博士、守備力関係
                if(getchar() == '\n') {
                    if(d_protect >= 10) {
                        Protect += 10;
                        cout << "\x1b[33m"
                             << "守備力"
                             << "\x1b[34m"
                             << "が10上がった。 ▼ "
                             << "\x1b[39m";
                    } else if(d_protect > 0) {
                        Protect += d_protect;
                        cout << "\x1b[33m"
                             << "守備力"
                             << "\x1b[34m"
                             << "が" << d_protect << "上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "守備力はもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }

                //ダイジョーブ博士、捕球関係
                if(getchar() == '\n') {
                    if(d_catching >= 10) {
                        Catching += 10;
                        cout << "\x1b[33m"
                             << "捕球"
                             << "\x1b[34m"
                             << "が10上がった。 ▼ "
                             << "\x1b[39m";
                    } else if(d_catching > 0) {
                        Catching += d_catching;
                        cout << "\x1b[33m"
                             << "捕球"
                             << "\x1b[34m"
                             << "が" << d_catching << "上がった。 ▼ "
                             << "\x1b[39m";
                    } else
                        cout << "\x1b[31m"
                             << "捕球はもうこれ以上上がりません。 ▼"
                             << "\x1b[39m";
                }

                condition = 5; //調子が絶好調に
            }                  //成功if終了(野手)
        }                      //成功判定終了
        else {
            if(Position == 1) {
                Ball_status -= 5;
                Control -= 10;
                Stamina -= 10;
                //下限調整
                if(Ball_status < 70)
                    Ball_status = 70;
                if(Control < 1)
                    Control = 1;
                if(Stamina < 1)
                    Stamina = 1;
                if(getchar() == '\n') {
                    system("clear");
                    Pawapuro_happy();
                    cout << "\x1b[33m"
                         << "球速"
                         << "\x1b[31m"
                         << "が5下がった。 ▼ "
                         << "\x1b[39m";
                }
                if(getchar() == '\n')
                    cout << "\x1b[33m"
                         << "コントロール"
                         << "\x1b[31m"
                         << "が10下がった。 ▼ "
                         << "\x1b[39m";
                if(getchar() == '\n')
                    cout << "\x1b[33m"
                         << "スタミナ"
                         << "\x1b[31m"
                         << "が10下がった。 ▼ "
                         << "\x1b[39m";
                if(Slider >= 2) {
                    Slider -= 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "スライダー"
                             << "\x1b[31m"
                             << "が1下がった。 ▼ "
                             << "\x1b[39m";
                }
                if(Curve >= 2) {
                    Curve -= 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "カーブ"
                             << "\x1b[31m"
                             << "が1下がった。 ▼ "
                             << "\x1b[39m";
                }
                if(Fork >= 2) {
                    Fork -= 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "フォーク"
                             << "\x1b[31m"
                             << "が1下がった。 ▼ "
                             << "\x1b[39m";
                }
                if(Sinker >= 2) {
                    Sinker -= 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "シンカー"
                             << "\x1b[31m"
                             << "が1下がった。 ▼ "
                             << "\x1b[39m";
                }
                if(Shoot >= 2) {
                    Shoot -= 1;
                    if(getchar() == '\n')
                        cout << "\x1b[33m"
                             << "シュート"
                             << "\x1b[31m"
                             << "が1下がった。 ▼ "
                             << "\x1b[39m";
                }
                condition = 1; //調子が絶不調に
            }                  //失敗if終了(投手)
            if((Position > 1) && (Position < 10)) {
                Trajectory -= 1;
                Meet -= 10;
                Power -= 10;
                Run -= 10;
                Sholder -= 10;
                Protect -= 10;
                Catching -= 10;
                //下限調整
                if(Trajectory < 1)
                    Trajectory = 1;
                if(Meet < 1)
                    Meet = 1;
                if(Power < 1)
                    Power = 1;
                if(Run < 1)
                    Run = 1;
                if(Sholder < 1)
                    Sholder = 1;
                if(Protect < 1)
                    Protect = 1;
                if(Catching < 1)
                    Catching = 1;

                if(getchar() == '\n') {
                    system("clear");
                    Pawapuro_happy();
                    cout << "\x1b[33m"
                         << "弾道"
                         << "\x1b[31m"
                         << "が10下がった。 ▼ "
                         << "\x1b[39m";
                }
                if(getchar() == '\n')
                    cout << "\x1b[33m"
                         << "ミート"
                         << "\x1b[31m"
                         << "が10下がった。 ▼ "
                         << "\x1b[39m";
                if(getchar() == '\n')
                    cout << "\x1b[33m"
                         << "パワー"
                         << "\x1b[31m"
                         << "が10下がった。 ▼ "
                         << "\x1b[39m";
                if(getchar() == '\n')
                    cout << "\x1b[33m"
                         << "走力"
                         << "\x1b[31m"
                         << "が10下がった。 ▼ "
                         << "\x1b[39m";
                if(getchar() == '\n')
                    cout << "\x1b[33m"
                         << "肩力"
                         << "\x1b[31m"
                         << "が10下がった。 ▼ "
                         << "\x1b[39m";
                if(getchar() == '\n')
                    cout << "\x1b[33m"
                         << "守備力"
                         << "\x1b[31m"
                         << "が10下がった。 ▼ "
                         << "\x1b[39m";
                if(getchar() == '\n')
                    cout << "\x1b[33m"
                         << "捕球"
                         << "\x1b[31m"
                         << "が10下がった。 ▼ "
                         << "\x1b[39m";
                condition = 1; //調子が絶不調に
            }                  //失敗if終了(野手)
        }                      //失敗判定終了
    }                          //実験実行選択if終了
    else {
        if(getchar() == '\n')
            cout << "[ダイジョーブ博士]:"
                    "「ソウデスカ。デハゲドー君、彼ヲ元ノ場所ニ戻シテオイテ下サ"
                    "イ。」▼ "
                 << endl;
        if(getchar() == '\n')
            cout << "[ゲドー君]:「ギョギョ。」▼ " << endl;
        if(getchar() == '\n')
            cout << "[" << Name << "]:「な、なにをする！」▼ " << endl;
        if(getchar() == '\n')
            cout << "[ダイジョーブ博士]:「動カナイデクダサイ。」▼ " << endl;
        if(getchar() == '\n')
            cout << "(ビリビリビリッ) ▼ " << endl;
        if(getchar() == '\n')
            cout << "うぎゃああああああああっ！！！ ▼ " << endl;
        if(getchar() == '\n')
            cout << "[" << Name << "]:「ハッ！　ここは？」▼ " << endl;
        if(getchar() == '\n')
            cout << "[" << Name << "]:「何があったんだっけ？」▼ " << endl;
        if(getchar() == '\n')
            cout << "[" << Name << "]:「よく覚えてない...」▼ " << endl;
        if(getchar() == '\n')
            cout << "[" << Name << "]:「ま、いいか！」▼ " << endl;
    }
} // Daijyoubu()終了

void Pitcher_Point_allocate(void) {
    int allocate_number;
    //各投手ポイントの長さ変数
    int length_muscle;
    int length_technique;
    int length_evolving;
    int length_spirit;
    int muscle_keep = muscle, technique_keep = technique,
        evolving_keep = evolving, spirit_keep = spirit;
    int Ball_keep = Ball, Control_keep = Control, Stamina_keep = Stamina,
        Slider_keep = Slider, Curve_keep = Curve, Fork_keep = Fork,
        Sinker_keep = Sinker, Shoot_keep = Shoot;
    char Control_keep_status, Stamina_keep_status, Slider_keep_status,
        Curve_keep_status, Fork_keep_status, Sinker_keep_status,
        Shoot_keep_status;

    //-----[コントロール判定]---------------------------------------
    if(Control >= 90)
        Control_keep_status = 'S';
    if((Control >= 80) && (Control < 90))
        Control_keep_status = 'A';
    if((Control >= 70) && (Control < 80))
        Control_keep_status = 'B';
    if((Control >= 60) && (Control < 70))
        Control_keep_status = 'C';
    if((Control >= 50) && (Control < 60))
        Control_keep_status = 'D';
    if((Control >= 40) && (Control < 50))
        Control_keep_status = 'E';
    if((Control >= 20) && (Control < 40))
        Control_keep_status = 'F';
    if(Control < 20)
        Control_keep_status = 'G';

    //-----[スタミナ判定]---------------------------------------
    if(Stamina >= 90)
        Stamina_keep_status = 'S';
    if((Stamina >= 80) && (Stamina < 90))
        Stamina_keep_status = 'A';
    if((Stamina >= 70) && (Stamina < 80))
        Stamina_keep_status = 'B';
    if((Stamina >= 60) && (Stamina < 70))
        Stamina_keep_status = 'C';
    if((Stamina >= 50) && (Stamina < 60))
        Stamina_keep_status = 'D';
    if((Stamina >= 40) && (Stamina < 50))
        Stamina_keep_status = 'E';
    if((Stamina >= 20) && (Stamina < 40))
        Stamina_keep_status = 'F';
    if(Stamina < 20)
        Stamina_keep_status = 'G';

    //-----[スライダー判定]-----------------------------------------
    if(Slider == 7)
        Slider_keep_status = 7;
    if(Slider == 6)
        Slider_keep_status = 6;
    if(Slider == 5)
        Slider_keep_status = 5;
    if(Slider == 4)
        Slider_keep_status = 4;
    if(Slider == 3)
        Slider_keep_status = 3;
    if(Slider == 2)
        Slider_keep_status = 2;
    if(Slider == 1)
        Slider_keep_status = 1;
    if(Slider == 0)
        Slider_keep_status = 0;

    //-----[カーブ判定]-----------------------------------------
    if(Curve == 7)
        Curve_keep_status = 7;
    if(Curve == 6)
        Curve_keep_status = 6;
    if(Curve == 5)
        Curve_keep_status = 5;
    if(Curve == 4)
        Curve_keep_status = 4;
    if(Curve == 3)
        Curve_keep_status = 3;
    if(Curve == 2)
        Curve_keep_status = 2;
    if(Curve == 1)
        Curve_keep_status = 1;
    if(Curve == 0)
        Curve_keep_status = 0;

    //-----[フォーク判定]-----------------------------------------
    if(Fork == 7)
        Fork_keep_status = 7;
    if(Fork == 6)
        Fork_keep_status = 6;
    if(Fork == 5)
        Fork_keep_status = 5;
    if(Fork == 4)
        Fork_keep_status = 4;
    if(Fork == 3)
        Fork_keep_status = 3;
    if(Fork == 2)
        Fork_keep_status = 2;
    if(Fork == 1)
        Fork_keep_status = 1;
    if(Fork == 0)
        Fork_keep_status = 0;

    //-----[シンカー判定]-----------------------------------------
    if(Sinker == 7)
        Sinker_keep_status = 7;
    if(Sinker == 6)
        Sinker_keep_status = 6;
    if(Sinker == 5)
        Sinker_keep_status = 5;
    if(Sinker == 4)
        Sinker_keep_status = 4;
    if(Sinker == 3)
        Sinker_keep_status = 3;
    if(Sinker == 2)
        Sinker_keep_status = 2;
    if(Sinker == 1)
        Sinker_keep_status = 1;
    if(Sinker == 0)
        Sinker_keep_status = 0;

    //-----[シュート判定]-----------------------------------------
    if(Shoot == 7)
        Shoot_keep_status = 7;
    if(Shoot == 6)
        Shoot_keep_status = 6;
    if(Shoot == 5)
        Shoot_keep_status = 5;
    if(Shoot == 4)
        Shoot_keep_status = 4;
    if(Shoot == 3)
        Shoot_keep_status = 3;
    if(Shoot == 2)
        Shoot_keep_status = 2;
    if(Shoot == 1)
        Shoot_keep_status = 1;
    if(Shoot == 0)
        Shoot_keep_status = 0;

ALLOCATE_PITCHER:
    //各投手能力値の長さ判定
    if((muscle >= 0) && (muscle < 10))
        length_muscle = 1;
    else if((muscle >= 10) && (muscle < 100))
        length_muscle = 2;
    else
        length_muscle = 3;

    if((technique >= 0) && (technique < 10))
        length_technique = 1;
    else if((technique >= 10) && (technique < 100))
        length_technique = 2;
    else
        length_technique = 3;

    if((evolving >= 0) && (evolving < 10))
        length_evolving = 1;
    else if((evolving >= 10) && (evolving < 100))
        length_evolving = 2;
    else
        length_evolving = 3;

    if((spirit >= 0) && (spirit < 10))
        length_spirit = 1;
    else if((spirit >= 10) && (spirit < 100))
        length_spirit = 2;
    else
        length_spirit = 3;

    //投手能力画面の空白調節部分
    string musclespan(5 - length_muscle, ' ');
    string techniquespan(5 - length_technique, ' ');
    string evolvingspan(5 - length_evolving, ' ');
    string spiritspan(5 - length_spirit, ' ');

    Pitcher_status_decide();

    //各投手能力値の長さ変数
    int length_Ball_keep;
    int length_Control_keep;
    int length_Stamina_keep;

    //各投手能力値の長さ判定
    if((Ball_keep >= 0) && (Ball_keep < 10))
        length_Ball_keep = 1;
    else if((Ball_keep >= 10) && (Ball_keep < 100))
        length_Ball_keep = 2;
    else
        length_Ball_keep = 3;

    if((Control_keep >= 0) && (Control_keep < 10))
        length_Control_keep = 1;
    else if((Control_keep >= 10) && (Control_keep < 100))
        length_Control_keep = 2;
    else
        length_Control_keep = 3;

    if((Stamina_keep >= 0) && (Stamina_keep < 10))
        length_Stamina_keep = 1;
    else if((Stamina_keep >= 10) && (Stamina_keep < 100))
        length_Stamina_keep = 2;
    else
        length_Stamina_keep = 3;

    if((Ball >= 0) && (Ball < 10))
        length_Ball = 1;
    else if((Ball >= 10) && (Ball < 100))
        length_Ball = 2;
    else
        length_Ball = 3;

    if((Control >= 0) && (Control < 10))
        length_Control = 1;
    else if((Control >= 10) && (Control < 100))
        length_Control = 2;
    else
        length_Control = 3;

    if((Stamina >= 0) && (Stamina < 10))
        length_Stamina = 1;
    else if((Stamina >= 10) && (Stamina < 100))
        length_Stamina = 2;
    else
        length_Stamina = 3;

    //投手能力画面の空白調節部分
    string Ball_keepspan(5 - length_Ball_keep, ' ');
    string Control_keepspan(5 - length_Control_keep, ' ');
    string Stamina_keepspan(5 - length_Stamina_keep, ' ');

    string Controlspan(5 - length_Control, ' ');
    string Staminaspan(5 - length_Stamina, ' ');
    string Ballspan(5 - length_Ball, ' ');
    // ALLOCATE_PITCHER:

    system("clear");
    cout << "[能力UP前]" << endl;
    cout << " ================================================================"
         << endl;
    cout << "| --------------------------  ---------------------------------- |"
         << endl;
    cout << "|| [球速] | [コン] | [スタ] || [ シュート ] " << Shoot_keep
         << "  | [スライダー] " << Slider_keep << " ||" << endl;
    cout << "||--------------------------||----------------------------------||"
         << endl;
    cout << "||   " << Ball_keep;
    cout << "  |  「";
    Control_color(Control_keep_status);
    cout << "」 |  「";
    Stamina_color(Stamina_keep_status);
    cout << "」 || [ シンカー ] " << Sinker_keep << "  | [  カーブ  ] "
         << Curve_keep << " ||" << endl;
    cout << "||--------------------------||----------------------------------||"
         << endl;
    cout << "||  km/h  |   " << Control_keep << Control_keepspan << "|   "
         << Stamina_keep << Stamina_keepspan << "|| [ フォーク ] " << Fork_keep
         << "  |                ||" << endl;
    cout << "| --------------------------  ---------------------------------- |"
         << endl;
    cout << " ================================================================"
         << endl;
    cout << "[能力UP後]" << endl;
    cout << " ================================================================"
         << endl;
    cout << "| --------------------------  ---------------------------------- |"
         << endl;
    cout << "|| [球速] | [コン] | [スタ] || [ シュート ] " << Shoot
         << "  | [スライダー] " << Slider << " ||" << endl;
    cout << "||--------------------------||----------------------------------||"
         << endl;
    cout << "||   " << Ball;
    cout << "  |  「";
    Control_color(Control_status);
    cout << "」 |  「";
    Stamina_color(Stamina_status);
    cout << "」 || [ シンカー ] " << Sinker << "  | [  カーブ  ] " << Curve
         << " ||" << endl;
    cout << "||--------------------------||----------------------------------||"
         << endl;
    cout << "||  km/h  |   " << Control << Controlspan << "|   " << Stamina
         << Staminaspan << "|| [ フォーク ] " << Fork << "  |                ||"
         << endl;
    cout << "| --------------------------  ---------------------------------- |"
         << endl;
    cout << " ================================================================"
         << endl;

    cout << "[経験値割り振り]" << endl;
    cout << " ======================================================= " << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "||                         | 筋力 | 技術 |変化球| 精神 ||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "||    現在の経験点    | -> |" << musclespan << muscle << " |"
         << techniquespan << technique << " |" << evolvingspan << evolving
         << " |" << spiritspan << spirit << " ||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [1]    [ 球速 ]    | ↑  |";
    Pitcher_Ball_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [2] [コントロール] | ↑  |";
    Pitcher_Control_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [3]   [スタミナ]   | ↑  |";
    Pitcher_Stamina_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [4]  [スライダー]  | ↑  |";
    Pitcher_Slider_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [5]    [カーブ]    | ↑  |";
    Pitcher_Curve_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [6]   [フォーク]   | ↑  |";
    Pitcher_Fork_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [7]   [シンカー]   | ↑  |";
    Pitcher_Sinker_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [8]   [シュート]   | ↑  |";
    Pitcher_Shoot_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << " ======================================================= " << endl;
    cout << "どの能力を上げますか？ ▼ " << endl;
    cout << "[[能力番号]] -> [1 ~ 8]" << endl;
    cout << "[[能力決定]] -> [9]" << endl;
    cout << "[[キャンセル]] -> [0]" << endl;
    cout << "選択 -> ";
    cin >> allocate_number;
    if(allocate_number == 9)
        return;
    if(allocate_number == 0) {

        //能力戻し
        Ball = Ball_keep;
        Control = Control_keep;
        Stamina = Stamina_keep;
        Slider = Slider_keep;
        Curve = Curve_keep;
        Fork = Fork_keep;
        Sinker = Sinker_keep;
        Shoot = Shoot_keep;

        //経験値戻し
        muscle = muscle_keep;
        technique = technique_keep;
        evolving = evolving_keep;
        spirit = spirit_keep;

        goto ALLOCATE_PITCHER;
    }

    //--[球速関係]------------------------------------------------------
    if(allocate_number == 1) {
        if(Ball == 165) {
            cout << "球速値は最大に達しています ▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        int i = 0;
        while(1) {
            Ball_point();
            if((muscle < 0) || (technique < 0) || (spirit < 0) ||
               (Ball == 165)) {
                if(Ball == Ball_keep) {
                    if(getchar() == '\n')
                        cout << "球速値はあげられません。▼ " << endl;
                    muscle = muscle_keep;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_PITCHER;
                }
                cout << "球速値は現在" << Ball << "まで上げることができます。▼ "
                     << endl;
                muscle = muscle_keep;
                technique = technique_keep;
                spirit = spirit_keep;
                Ball = Ball_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "球速値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Ball_p;
        if(Ball_p == 0)
            goto ALLOCATE_PITCHER;
        Ball_p = Ball_p - Ball;
        if(Ball_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        while(1) {
            i++;
            Ball_point();
            if((muscle < 0) || (technique < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                muscle = muscle_keep;
                technique = technique_keep;
                spirit = spirit_keep;
                Ball = Ball_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_PITCHER;
            } // if
            if(i == Ball_p)
                break;
        } // while
        goto ALLOCATE_PITCHER;
    }

    //--[コントロール関係]------------------------------------------------------
    if(allocate_number == 2) {
        if(Control == 100) {
            cout << "コントロール値は最大に達しています ▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        int i = 0;
        while(1) {
            Control_point();
            if((technique < 0) || (spirit < 0) || (Control == 100)) {
                if(Control == Control_keep) {
                    if(getchar() == '\n')
                        cout << "コントロール値はあげられません。▼ " << endl;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_PITCHER;
                }
                cout << "コントロール値は現在" << Control
                     << "まで上げることができます。▼ " << endl;
                technique = technique_keep;
                spirit = spirit_keep;
                Control = Control_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "コントロール値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Control_p;
        if(Control_p == 0)
            goto ALLOCATE_PITCHER;
        Control_p = Control_p - Control;
        if(Control_p <= 0) {
            cout << "現能力値以下です ▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        while(1) {
            i++;
            Control_point();
            if((technique < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りません　▼ ";
                technique = technique_keep;
                spirit = spirit_keep;
                Control = Control_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_PITCHER;
            } // if
            if(i == Control_p)
                break;
        } // while
        goto ALLOCATE_PITCHER;
    }

    //--[スタミナ関係]------------------------------------------------------
    if(allocate_number == 3) {
        if(Stamina == 100) {
            cout << "スタミナ値は最大に達しています ▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        int i = 0;
        while(1) {
            Stamina_point();
            if((muscle < 0) || (spirit < 0) || (Stamina == 100)) {
                if(Stamina == Stamina_keep) {
                    if(getchar() == '\n')
                        cout << "スタミナ値はあげられません。▼ " << endl;
                    muscle = muscle_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_PITCHER;
                }
                cout << "スタミナ値は現在" << Stamina
                     << "まで上げることができます。▼ " << endl;
                muscle = muscle_keep;
                spirit = spirit_keep;
                Stamina = Stamina_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "スタミナ値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Stamina_p;
        if(Stamina_p == 0)
            goto ALLOCATE_PITCHER;
        Stamina_p = Stamina_p - Stamina;
        if(Stamina_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        while(1) {
            i++;
            Stamina_point();
            if((muscle < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                muscle = muscle_keep;
                spirit = spirit_keep;
                Stamina = Stamina_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_PITCHER;
            } // if
            if(i == Stamina_p)
                break;
        } // while
        goto ALLOCATE_PITCHER;
    }

    //--[スライダー関係]------------------------------------------------------
    if(allocate_number == 4) {
        if(Slider == 7) {
            cout << "スライダー値は最大に達しています ▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        int i = 0;
        while(1) {
            Slider_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0) ||
               (Slider == 7)) {
                if(Slider == Slider_keep) {
                    if(getchar() == '\n')
                        cout << "スライダー値はあげられません。▼ " << endl;
                    evolving = evolving_keep;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_PITCHER;
                }
                cout << "スライダー値は現在" << Slider
                     << "まで上げることができます。▼ " << endl;
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Slider = Slider_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "スライダー値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Slider_p;
        if(Slider_p == 0)
            goto ALLOCATE_PITCHER;
        Slider_p = Slider_p - Slider;
        if(Slider_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        while(1) {
            i++;
            Slider_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Slider = Slider_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_PITCHER;
            } // if
            if(i == Slider_p)
                break;
        } // while
        goto ALLOCATE_PITCHER;
    }

    //--[カーブ関係]------------------------------------------------------
    if(allocate_number == 5) {
        if(Curve == 7) {
            cout << "カーブ値は最大に達しています ▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        int i = 0;
        while(1) {
            Curve_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0) ||
               (Curve == 7)) {
                if(Curve == Curve_keep) {
                    if(getchar() == '\n')
                        cout << "カーブ値はあげられません。▼ " << endl;
                    evolving = evolving_keep;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_PITCHER;
                }
                cout << "カーブ値は現在" << Curve
                     << "まで上げることができます。▼ " << endl;
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Curve = Curve_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "カーブ値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Curve_p;
        if(Curve_p == 0)
            goto ALLOCATE_PITCHER;
        Curve_p = Curve_p - Curve;
        if(Curve_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        while(1) {
            i++;
            Curve_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Curve = Curve_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_PITCHER;
            } // if
            if(i == Curve_p)
                break;
        } // while
        goto ALLOCATE_PITCHER;
    }

    //--[フォーク関係]------------------------------------------------------
    if(allocate_number == 6) {
        if(Fork == 7) {
            cout << "フォーク値は最大に達しています ▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        int i = 0;
        while(1) {
            Fork_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0) ||
               (Fork == 7)) {
                if(Fork == Fork_keep) {
                    if(getchar() == '\n')
                        cout << "フォーク値はあげられません。▼ " << endl;
                    evolving = evolving_keep;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_PITCHER;
                }
                cout << "フォーク値は現在" << Slider
                     << "まで上げることができます。▼ " << endl;
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Fork = Fork_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "フォーク値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Fork_p;
        if(Fork_p == 0)
            goto ALLOCATE_PITCHER;
        Fork_p = Fork_p - Fork;
        if(Fork_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        while(1) {
            i++;
            Fork_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Fork = Fork_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_PITCHER;
            } // if
            if(i == Fork_p)
                break;
        } // while
        goto ALLOCATE_PITCHER;
    }

    //--[シンカー関係]------------------------------------------------------
    if(allocate_number == 7) {
        if(Sinker == 7) {
            cout << "シンカー値は最大に達しています ▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        int i = 0;
        while(1) {
            Sinker_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0) ||
               (Sinker == 7)) {
                if(Sinker == Sinker_keep) {
                    if(getchar() == '\n')
                        cout << "シンカー値はあげられません。▼ " << endl;
                    evolving = evolving_keep;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_PITCHER;
                }
                cout << "シンカー値は現在" << Sinker
                     << "まで上げることができます。▼ " << endl;
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Sinker = Sinker_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "シンカー値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Sinker_p;
        if(Sinker_p == 0)
            goto ALLOCATE_PITCHER;
        Sinker_p = Sinker_p - Sinker;
        if(Sinker_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        while(1) {
            i++;
            Sinker_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Sinker = Sinker_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_PITCHER;
            } // if
            if(i == Sinker_p)
                break;
        } // while
        goto ALLOCATE_PITCHER;
    }

    //--[シュート関係]------------------------------------------------------
    if(allocate_number == 8) {
        if(Shoot == 7) {
            cout << "シュート値は最大に達しています ▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        int i = 0;
        while(1) {
            Shoot_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0) ||
               (Shoot == 7)) {
                if(Shoot == Shoot_keep) {
                    if(getchar() == '\n')
                        cout << "シュート値はあげられません。▼ " << endl;
                    evolving = evolving_keep;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_PITCHER;
                }
                cout << "シュート値は現在" << Shoot
                     << "まで上げることができます。▼ " << endl;
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Shoot = Shoot_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "シュート値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Shoot_p;
        if(Shoot_p == 0)
            goto ALLOCATE_PITCHER;
        Shoot_p = Shoot_p - Shoot;
        if(Shoot_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_PITCHER;
        }
        while(1) {
            i++;
            Shoot_point();
            if((technique < 0) || (evolving < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                technique = technique_keep;
                evolving = evolving_keep;
                spirit = spirit_keep;
                Shoot = Shoot_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_PITCHER;
            } // if
            if(i == Shoot_p)
                break;
        } // while
        goto ALLOCATE_PITCHER;
    }
}

void Ball_point(void) {
    //-----[球速ポイント判定]-----------------------------------------
    if(Ball == 164) {
        muscle -= 69 * genius_point;
        if(muscle < 0)
            return;
        technique -= 42 * genius_point;
        if(technique < 0)
            return;
        spirit -= 26 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 163) {
        muscle -= 68 * genius_point;
        if(muscle < 0)
            return;
        technique -= 41 * genius_point;
        if(technique < 0)
            return;
        spirit -= 25 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 162) {
        muscle -= 67 * genius_point;
        if(muscle < 0)
            return;
        technique -= 40 * genius_point;
        if(technique < 0)
            return;
        spirit -= 24 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 161) {
        muscle -= 66 * genius_point;
        if(muscle < 0)
            return;
        technique -= 39 * genius_point;
        if(technique < 0)
            return;
        spirit -= 23 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 160) {
        muscle -= 65 * genius_point;
        if(muscle < 0)
            return;
        technique -= 38 * genius_point;
        if(technique < 0)
            return;
        spirit -= 22 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 159) {
        muscle -= 64 * genius_point;
        if(muscle < 0)
            return;
        technique -= 37 * genius_point;
        if(technique < 0)
            return;
        spirit -= 21 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 158) {
        muscle -= 63 * genius_point;
        if(muscle < 0)
            return;
        technique -= 36 * genius_point;
        if(technique < 0)
            return;
        spirit -= 20 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 157) {
        muscle -= 62 * genius_point;
        if(muscle < 0)
            return;
        technique -= 35 * genius_point;
        if(technique < 0)
            return;
        spirit -= 19 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 156) {
        muscle -= 61 * genius_point;
        if(muscle < 0)
            return;
        technique -= 34 * genius_point;
        if(technique < 0)
            return;
        spirit -= 18 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 155) {
        muscle -= 60 * genius_point;
        if(muscle < 0)
            return;
        technique -= 33 * genius_point;
        if(technique < 0)
            return;
        spirit -= 17 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 154) {
        muscle -= 59 * genius_point;
        if(muscle < 0)
            return;
        technique -= 32 * genius_point;
        if(technique < 0)
            return;
        spirit -= 16 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 153) {
        muscle -= 58 * genius_point;
        if(muscle < 0)
            return;
        technique -= 31 * genius_point;
        if(technique < 0)
            return;
        spirit -= 15 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 152) {
        muscle -= 57 * genius_point;
        if(muscle < 0)
            return;
        technique -= 30 * genius_point;
        if(technique < 0)
            return;
        spirit -= 14 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 151) {
        muscle -= 56 * genius_point;
        if(muscle < 0)
            return;
        technique -= 29 * genius_point;
        if(technique < 0)
            return;
        spirit -= 13 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 150) {
        muscle -= 55 * genius_point;
        if(muscle < 0)
            return;
        technique -= 28 * genius_point;
        if(technique < 0)
            return;
        spirit -= 12 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 149) {
        muscle -= 49 * genius_point;
        if(muscle < 0)
            return;
        technique -= 27 * genius_point;
        if(technique < 0)
            return;
        spirit -= 11 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 148) {
        muscle -= 48 * genius_point;
        if(muscle < 0)
            return;
        technique -= 26 * genius_point;
        if(technique < 0)
            return;
        spirit -= 10 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 147) {
        muscle -= 47 * genius_point;
        if(muscle < 0)
            return;
        technique -= 25 * genius_point;
        if(technique < 0)
            return;
        spirit -= 9 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 146) {
        muscle -= 46 * genius_point;
        if(muscle < 0)
            return;
        technique -= 24 * genius_point;
        if(technique < 0)
            return;
        spirit -= 8 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 145) {
        muscle -= 45 * genius_point;
        if(muscle < 0)
            return;
        technique -= 23 * genius_point;
        if(technique < 0)
            return;
        spirit -= 7 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 144) {
        muscle -= 39 * genius_point;
        if(muscle < 0)
            return;
        technique -= 22 * genius_point;
        if(technique < 0)
            return;
        spirit -= 6 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 143) {
        muscle -= 38 * genius_point;
        if(muscle < 0)
            return;
        technique -= 21 * genius_point;
        if(technique < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 142) {
        muscle -= 37 * genius_point;
        if(muscle < 0)
            return;
        technique -= 20 * genius_point;
        if(technique < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 141) {
        muscle -= 36 * genius_point;
        if(muscle < 0)
            return;
        technique -= 19 * genius_point;
        if(technique < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball == 140) {
        muscle -= 35 * genius_point;
        if(muscle < 0)
            return;
        technique -= 18 * genius_point;
        if(technique < 0)
            return;
        spirit -= 2 * genius_point;
        if(spirit < 0)
            return;
        Ball++;
    }
    if((Ball > 134) && (Ball < 140)) {
        muscle -= 26 * genius_point;
        if(muscle < 0)
            return;
        technique -= 12 * genius_point;
        if(technique < 0)
            return;
        spirit -= 1;
        if(spirit < 0)
            return;
        Ball++;
    }
    if((Ball > 129) && (Ball < 135)) {
        muscle -= 25 * genius_point;
        if(muscle < 0)
            return;
        technique -= 11 * genius_point;
        if(technique < 0)
            return;
        spirit -= 1;
        if(spirit < 0)
            return;
        Ball++;
    }
    if((Ball > 119) && (Ball < 130)) {
        muscle -= 24 * genius_point;
        if(muscle < 0)
            return;
        technique -= 10 * genius_point;
        if(technique < 0)
            return;
        spirit -= 1;
        if(spirit < 0)
            return;
        Ball++;
    }
    if(Ball < 120) {
        muscle -= 20 * genius_point;
        if(muscle < 0)
            return;
        technique -= 7 * genius_point;
        if(technique < 0)
            return;
        spirit -= 1;
        if(spirit < 0)
            return;
        Ball++;
    }
}

void Control_point(void) {
    //-----[コントロールポイント判定]-----------------------------------------
    if((Control >= 90) && (Control < 100)) {
        technique -= 26 * genius_point;
        if(agile < 0)
            return;
        spirit -= 16 * genius_point;
        if(spirit < 0)
            return;
        Control++;
    }
    if((Control >= 80) && (Control < 90)) {
        technique -= 13 * genius_point;
        if(agile < 0)
            return;
        spirit -= 8 * genius_point;
        if(spirit < 0)
            return;
        Control++;
    }
    if((Control >= 70) && (Control < 80)) {
        technique -= 12 * genius_point;
        if(agile < 0)
            return;
        spirit -= 8 * genius_point;
        if(spirit < 0)
            return;
        Control++;
    }
    if((Control >= 60) && (Control < 70)) {
        technique -= 11 * genius_point;
        if(agile < 0)
            return;
        spirit -= 8 * genius_point;
        if(spirit < 0)
            return;
        Control++;
    }
    if((Control >= 50) && (Control < 60)) {
        technique -= 10 * genius_point;
        if(agile < 0)
            return;
        spirit -= 7 * genius_point;
        if(spirit < 0)
            return;
        Control++;
    }
    if((Control >= 40) && (Control < 50)) {
        technique -= 9 * genius_point;
        if(agile < 0)
            return;
        spirit -= 7 * genius_point;
        if(spirit < 0)
            return;
        Control++;
    }
    if((Control >= 20) && (Control < 40)) {
        technique -= 8 * genius_point;
        if(agile < 0)
            return;
        spirit -= 6 * genius_point;
        if(spirit < 0)
            return;
        Control++;
    }
    if(Control < 20) {
        technique -= 7 * genius_point;
        if(agile < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Control++;
    }
}

void Stamina_point(void) {
    //-----[スタミナポイント判定]-----------------------------------------
    if((Stamina >= 90) && (Stamina < 100)) {
        muscle -= 10 * genius_point;
        if(agile < 0)
            return;
        spirit -= 7 * genius_point;
        if(spirit < 0)
            return;
        Stamina++;
    }
    if((Stamina >= 80) && (Stamina < 90)) {
        muscle -= 10 * genius_point;
        if(agile < 0)
            return;
        spirit -= 6 * genius_point;
        if(spirit < 0)
            return;
        Stamina++;
    }
    if((Stamina >= 70) && (Stamina < 80)) {
        muscle -= 9 * genius_point;
        if(agile < 0)
            return;
        spirit -= 6 * genius_point;
        if(spirit < 0)
            return;
        Stamina++;
    }
    if((Stamina >= 60) && (Stamina < 70)) {
        muscle -= 9 * genius_point;
        if(agile < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Stamina++;
    }
    if((Stamina >= 50) && (Stamina < 60)) {
        muscle -= 8 * genius_point;
        if(agile < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Stamina++;
    }
    if((Stamina >= 40) && (Stamina < 50)) {
        muscle -= 8 * genius_point;
        if(agile < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Stamina++;
    }
    if((Stamina >= 20) && (Stamina < 40)) {
        muscle -= 7 * genius_point;
        if(agile < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Stamina++;
    }
    if(Stamina < 20) {
        muscle -= 7 * genius_point;
        if(agile < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Stamina++;
    }
}

void Slider_point(void) {
    //-----[スライダーポイント判定]-----------------------------------------
    if(Slider == 6) {
        technique -= 26 * genius_point;
        if(technique < 0)
            return;
        evolving -= 132 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Slider++;
    }
    if(Slider == 5) {
        technique -= 22 * genius_point;
        if(technique < 0)
            return;
        evolving -= 117 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Slider++;
    }
    if(Slider == 4) {
        technique -= 19 * genius_point;
        if(technique < 0)
            return;
        evolving -= 102 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Slider++;
    }
    if(Slider == 3) {
        technique -= 16 * genius_point;
        if(technique < 0)
            return;
        evolving -= 58 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Slider++;
    }
    if(Slider == 2) {
        technique -= 13 * genius_point;
        if(technique < 0)
            return;
        evolving -= 48 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Slider++;
    }
    if(Slider == 1) {
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        evolving -= 38 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 2 * genius_point;
        if(spirit < 0)
            return;
        Slider++;
    }
    if(Slider == 0) {
        technique -= 5 * genius_point;
        if(technique < 0)
            return;
        evolving -= 28 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 1;
        if(spirit < 0)
            return;
        Slider++;
    }
}

void Curve_point(void) {
    //-----[カーブポイント判定]-----------------------------------------
    if(Curve == 6) {
        technique -= 26 * genius_point;
        if(technique < 0)
            return;
        evolving -= 132 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Curve++;
    }
    if(Curve == 5) {
        technique -= 22 * genius_point;
        if(technique < 0)
            return;
        evolving -= 117 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Curve++;
    }
    if(Curve == 4) {
        technique -= 19 * genius_point;
        if(technique < 0)
            return;
        evolving -= 102 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Curve++;
    }
    if(Curve == 3) {
        technique -= 16 * genius_point;
        if(technique < 0)
            return;
        evolving -= 58 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Curve++;
    }
    if(Curve == 2) {
        technique -= 13 * genius_point;
        if(technique < 0)
            return;
        evolving -= 48 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Curve++;
    }
    if(Curve == 1) {
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        evolving -= 38 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 2 * genius_point;
        if(spirit < 0)
            return;
        Curve++;
    }
    if(Curve == 0) {
        technique -= 5 * genius_point;
        if(technique < 0)
            return;
        evolving -= 28 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 1;
        if(spirit < 0)
            return;
        Curve++;
    }
}

void Fork_point(void) {
    //-----[フォークポイント判定]-----------------------------------------
    if(Fork == 6) {
        technique -= 26 * genius_point;
        if(technique < 0)
            return;
        evolving -= 132 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Fork++;
    }
    if(Fork == 5) {
        technique -= 22 * genius_point;
        if(technique < 0)
            return;
        evolving -= 117 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Fork++;
    }
    if(Fork == 4) {
        technique -= 19 * genius_point;
        if(technique < 0)
            return;
        evolving -= 102 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Fork++;
    }
    if(Fork == 3) {
        technique -= 16 * genius_point;
        if(technique < 0)
            return;
        evolving -= 58 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Fork++;
    }
    if(Fork == 2) {
        technique -= 13 * genius_point;
        if(technique < 0)
            return;
        evolving -= 48 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Fork++;
    }
    if(Fork == 1) {
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        evolving -= 38 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 2 * genius_point;
        if(spirit < 0)
            return;
        Fork++;
    }
    if(Fork == 0) {
        technique -= 5 * genius_point;
        if(technique < 0)
            return;
        evolving -= 28 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 1;
        if(spirit < 0)
            return;
        Fork++;
    }
}

void Sinker_point(void) {
    //-----[シンカーポイント判定]-----------------------------------------
    if(Sinker == 6) {
        technique -= 26 * genius_point;
        if(technique < 0)
            return;
        evolving -= 132 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Sinker++;
    }
    if(Sinker == 5) {
        technique -= 22 * genius_point;
        if(technique < 0)
            return;
        evolving -= 117 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Sinker++;
    }
    if(Sinker == 4) {
        technique -= 19 * genius_point;
        if(technique < 0)
            return;
        evolving -= 102 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Sinker++;
    }
    if(Sinker == 3) {
        technique -= 16 * genius_point;
        if(technique < 0)
            return;
        evolving -= 58 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Sinker++;
    }
    if(Sinker == 2) {
        technique -= 13 * genius_point;
        if(technique < 0)
            return;
        evolving -= 48 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Sinker++;
    }
    if(Sinker == 1) {
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        evolving -= 38 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 2 * genius_point;
        if(spirit < 0)
            return;
        Sinker++;
    }
    if(Sinker == 0) {
        technique -= 5 * genius_point;
        if(technique < 0)
            return;
        evolving -= 28 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 1;
        if(spirit < 0)
            return;
        Sinker++;
    }
}

void Shoot_point(void) {
    //-----[シュートポイント判定]-----------------------------------------
    if(Shoot == 6) {
        technique -= 26 * genius_point;
        if(technique < 0)
            return;
        evolving -= 132 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Shoot++;
    }
    if(Shoot == 5) {
        technique -= 22 * genius_point;
        if(technique < 0)
            return;
        evolving -= 117 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Shoot++;
    }
    if(Shoot == 4) {
        technique -= 19 * genius_point;
        if(technique < 0)
            return;
        evolving -= 102 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Shoot++;
    }
    if(Shoot == 3) {
        technique -= 16 * genius_point;
        if(technique < 0)
            return;
        evolving -= 58 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Shoot++;
    }
    if(Shoot == 2) {
        technique -= 13 * genius_point;
        if(technique < 0)
            return;
        evolving -= 48 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Shoot++;
    }
    if(Shoot == 1) {
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        evolving -= 38 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 2 * genius_point;
        if(spirit < 0)
            return;
        Shoot++;
    }
    if(Shoot == 0) {
        technique -= 5 * genius_point;
        if(technique < 0)
            return;
        evolving -= 28 * genius_point;
        if(evolving < 0)
            return;
        spirit -= 1;
        if(spirit < 0)
            return;
        Shoot++;
    }
}

void Batter_Point_allocate(void) {
    int allocate_number;
    //各野手ポイントの長さ変数
    int length_muscle;
    int length_agile;
    int length_technique;
    int length_spirit;
    int muscle_keep = muscle, agile_keep = agile, technique_keep = technique,
        spirit_keep = spirit;
    int Trajectory_keep = Trajectory, Meet_keep = Meet, Power_keep = Power,
        Run_keep = Run, Sholder_keep = Sholder, Protect_keep = Protect,
        Catching_keep = Catching;
    char Trajectory_keep_status, Meet_keep_status, Power_keep_status,
        Run_keep_status, Sholder_keep_status, Protect_keep_status,
        Catching_keep_status;

    //能力保持用ステータスデータ判定
    //-----[弾道判定]---------------------------------------
    if(Trajectory == 4)
        Trajectory_keep_status = '4';
    if(Trajectory == 3)
        Trajectory_keep_status = '3';
    if(Trajectory == 2)
        Trajectory_keep_status = '2';
    if(Trajectory == 1)
        Trajectory_keep_status = '1';

    //-----[ミート判定]---------------------------------------
    if(Meet >= 90)
        Meet_keep_status = 'S';
    if((Meet >= 80) && (Meet < 90))
        Meet_keep_status = 'A';
    if((Meet >= 70) && (Meet < 80))
        Meet_keep_status = 'B';
    if((Meet >= 60) && (Meet < 70))
        Meet_keep_status = 'C';
    if((Meet >= 50) && (Meet < 60))
        Meet_keep_status = 'D';
    if((Meet >= 40) && (Meet < 50))
        Meet_keep_status = 'E';
    if((Meet >= 20) && (Meet < 40))
        Meet_keep_status = 'F';
    if(Meet < 20)
        Meet_keep_status = 'G';

    //-----[パワー判定]---------------------------------------
    if(Power >= 90)
        Power_keep_status = 'S';
    if((Power >= 80) && (Power < 90))
        Power_keep_status = 'A';
    if((Power >= 70) && (Power < 80))
        Power_keep_status = 'B';
    if((Power >= 60) && (Power < 70))
        Power_keep_status = 'C';
    if((Power >= 50) && (Power < 60))
        Power_keep_status = 'D';
    if((Power >= 40) && (Power < 50))
        Power_keep_status = 'E';
    if((Power >= 20) && (Power < 40))
        Power_keep_status = 'F';
    if(Power < 20)
        Power_keep_status = 'G';

    //-----[走力判定]-----------------------------------------
    if(Run >= 90)
        Run_keep_status = 'S';
    if((Run >= 80) && (Run < 90))
        Run_keep_status = 'A';
    if((Run >= 70) && (Run < 80))
        Run_keep_status = 'B';
    if((Run >= 60) && (Run < 70))
        Run_keep_status = 'C';
    if((Run >= 50) && (Run < 60))
        Run_keep_status = 'D';
    if((Run >= 40) && (Run < 50))
        Run_keep_status = 'E';
    if((Run >= 20) && (Run < 40))
        Run_keep_status = 'F';
    if(Run < 20)
        Run_keep_status = 'G';

    //-----[肩力判定]-----------------------------------------
    if(Sholder >= 90)
        Sholder_keep_status = 'S';
    if((Sholder >= 80) && (Sholder < 90))
        Sholder_keep_status = 'A';
    if((Sholder >= 70) && (Sholder < 80))
        Sholder_keep_status = 'B';
    if((Sholder >= 60) && (Sholder < 70))
        Sholder_keep_status = 'C';
    if((Sholder >= 50) && (Sholder < 60))
        Sholder_keep_status = 'D';
    if((Sholder >= 40) && (Sholder < 50))
        Sholder_keep_status = 'E';
    if((Sholder >= 20) && (Sholder < 40))
        Sholder_keep_status = 'F';
    if(Sholder < 20)
        Sholder_keep_status = 'G';

    //-----[守備力判定]---------------------------------------
    if(Protect >= 90)
        Protect_keep_status = 'S';
    if((Protect >= 80) && (Protect < 90))
        Protect_keep_status = 'A';
    if((Protect >= 70) && (Protect < 80))
        Protect_keep_status = 'B';
    if((Protect >= 60) && (Protect < 70))
        Protect_keep_status = 'C';
    if((Protect >= 50) && (Protect < 60))
        Protect_keep_status = 'D';
    if((Protect >= 40) && (Protect < 50))
        Protect_keep_status = 'E';
    if((Protect >= 20) && (Protect < 40))
        Protect_keep_status = 'F';
    if(Protect < 20)
        Protect_keep_status = 'G';

    //-----[捕球判定]-----------------------------------------
    if(Catching >= 90)
        Catching_keep_status = 'S';
    if((Catching >= 80) && (Catching < 90))
        Catching_keep_status = 'A';
    if((Catching >= 70) && (Catching < 80))
        Catching_keep_status = 'B';
    if((Catching >= 60) && (Catching < 70))
        Catching_keep_status = 'C';
    if((Catching >= 50) && (Catching < 60))
        Catching_keep_status = 'D';
    if((Catching >= 40) && (Catching < 50))
        Catching_keep_status = 'E';
    if((Catching >= 20) && (Catching < 40))
        Catching_keep_status = 'F';
    if(Catching < 20)
        Catching_keep_status = 'G';

ALLOCATE_BATTER:
    //各野手能力値の長さ判定
    if((muscle >= 0) && (muscle < 10))
        length_muscle = 1;
    else if((muscle >= 10) && (muscle < 100))
        length_muscle = 2;
    else
        length_muscle = 3;

    if((agile >= 0) && (agile < 10))
        length_agile = 1;
    else if((agile >= 10) && (agile < 100))
        length_agile = 2;
    else
        length_agile = 3;

    if((technique >= 0) && (technique < 10))
        length_technique = 1;
    else if((technique >= 10) && (technique < 100))
        length_technique = 2;
    else
        length_technique = 3;

    if((spirit >= 0) && (spirit < 10))
        length_spirit = 1;
    else if((spirit >= 10) && (spirit < 100))
        length_spirit = 2;
    else
        length_spirit = 3;

    //野手能力画面の空白調節部分
    string musclespan(5 - length_muscle, ' ');
    string agilespan(5 - length_agile, ' ');
    string techniquespan(5 - length_technique, ' ');
    string spiritspan(5 - length_spirit, ' ');

    Batter_status_decide();

    //各野手能力値の長さ変数
    int length_Meet_keep;
    int length_Power_keep;
    int length_Run_keep;
    int length_Sholder_keep;
    int length_Protect_keep;
    int length_Catching_keep;

    //各野手能力値の長さ判定
    if((Meet_keep >= 0) && (Meet_keep < 10))
        length_Meet_keep = 1;
    else if((Meet_keep >= 10) && (Meet_keep < 100))
        length_Meet_keep = 2;
    else
        length_Meet_keep = 3;

    if((Power_keep >= 0) && (Power_keep < 10))
        length_Power_keep = 1;
    else if((Power_keep >= 10) && (Power_keep < 100))
        length_Power_keep = 2;
    else
        length_Meet_keep = 3;

    if((Run_keep >= 0) && (Run_keep < 10))
        length_Run_keep = 1;
    else if((Run_keep >= 10) && (Run_keep < 100))
        length_Run_keep = 2;
    else
        length_Meet_keep = 3;

    if((Sholder_keep >= 0) && (Sholder_keep < 10))
        length_Sholder_keep = 1;
    else if((Sholder_keep >= 10) && (Sholder_keep < 100))
        length_Sholder_keep = 2;
    else
        length_Meet_keep = 3;

    if((Protect_keep >= 0) && (Protect_keep < 10))
        length_Protect_keep = 1;
    else if((Protect_keep >= 10) && (Protect_keep < 100))
        length_Protect_keep = 2;
    else
        length_Protect_keep = 3;

    if((Catching_keep >= 0) && (Catching_keep < 10))
        length_Catching_keep = 1;
    else if((Catching_keep >= 10) && (Catching_keep < 100))
        length_Catching_keep = 2;
    else
        length_Catching_keep = 3;

    if((Meet >= 0) && (Meet < 10))
        length_Meet = 1;
    else if((Meet >= 10) && (Meet < 100))
        length_Meet = 2;
    else
        length_Meet = 3;

    if((Power >= 0) && (Power < 10))
        length_Power = 1;
    else if((Power >= 10) && (Power < 100))
        length_Power = 2;
    else
        length_Meet = 3;

    if((Run >= 0) && (Run < 10))
        length_Run = 1;
    else if((Run >= 10) && (Run < 100))
        length_Run = 2;
    else
        length_Meet = 3;

    if((Sholder >= 0) && (Sholder < 10))
        length_Sholder = 1;
    else if((Sholder >= 10) && (Sholder < 100))
        length_Sholder = 2;
    else
        length_Meet = 3;

    if((Protect >= 0) && (Protect < 10))
        length_Protect = 1;
    else if((Protect >= 10) && (Protect < 100))
        length_Protect = 2;
    else
        length_Protect = 3;

    if((Catching >= 0) && (Catching < 10))
        length_Catching = 1;
    else if((Catching >= 10) && (Catching < 100))
        length_Catching = 2;
    else
        length_Catching = 3;

    //野手能力画面の空白調節部分
    string Meet_keepspan(5 - length_Meet_keep, ' ');
    string Power_keepspan(5 - length_Power_keep, ' ');
    string Run_keepspan(5 - length_Run_keep, ' ');
    string Sholder_keepspan(5 - length_Sholder_keep, ' ');
    string Protect_keepspan(5 - length_Protect_keep, ' ');
    string Catching_keepspan(5 - length_Catching_keep, ' ');

    string Meetspan(5 - length_Meet, ' ');
    string Powerspan(5 - length_Power, ' ');
    string Runspan(5 - length_Run, ' ');
    string Sholderspan(5 - length_Sholder, ' ');
    string Protectspan(5 - length_Protect, ' ');
    string Catchingspan(5 - length_Catching, ' ');
    // ALLOCATE_BATTER:

    system("clear");
    cout << "[能力UP前]" << endl;
    cout << " ================================================================"
         << endl;
    cout << "| -------------------------------------------------------------- |"
         << endl;
    cout << "|| [弾道] |[ミート]|[パワー]| [走力] | [肩力] |[守備力]| [捕球] ||"
         << endl;
    cout << "||--------------------------------------------------------------||"
         << endl;
    cout << "||   ";
    Trajectory_color(Trajectory_keep_status);
    cout << "    |  「";
    Meet_color(Meet_keep_status);
    cout << "」 |  「";
    Power_color(Power_keep_status);
    cout << "」 |  「";
    Run_color(Run_keep_status);
    cout << "」 |  「";
    Sholder_color(Sholder_keep_status);
    cout << "」 |  「";
    Protect_color(Protect_keep_status);
    cout << "」 |  「";
    Catching_color(Catching_keep_status);
    cout << "」 ||" << endl;
    cout << "||--------------------------------------------------------------||"
         << endl;
    cout << "||   " << Trajectory_keep_status << "    |   " << Meet_keep
         << Meet_keepspan << "|   " << Power_keep << Power_keepspan << "|   "
         << Run_keep << Run_keepspan << "|   " << Sholder_keep
         << Sholder_keepspan << "|   " << Protect_keep << Protect_keepspan
         << "|   " << Catching_keep << Catching_keepspan << "||" << endl;
    cout << "| -------------------------------------------------------------- |"
         << endl;
    cout << " ================================================================"
         << endl;
    cout << "[能力UP後]" << endl;
    cout << " ================================================================"
         << endl;
    cout << "| -------------------------------------------------------------- |"
         << endl;
    cout << "|| [弾道] |[ミート]|[パワー]| [走力] | [肩力] |[守備力]| [捕球] ||"
         << endl;
    cout << "||--------------------------------------------------------------||"
         << endl;
    cout << "||   ";
    Trajectory_color(Trajectory_status);
    cout << "    |  「";
    Meet_color(Meet_status);
    cout << "」 |  「";
    Power_color(Power_status);
    cout << "」 |  「";
    Run_color(Run_status);
    cout << "」 |  「";
    Sholder_color(Sholder_status);
    cout << "」 |  「";
    Protect_color(Protect_status);
    cout << "」 |  「";
    Catching_color(Catching_status);
    cout << "」 ||" << endl;
    cout << "||--------------------------------------------------------------||"
         << endl;
    cout << "||   " << Trajectory_status << "    |   " << Meet << Meetspan
         << "|   " << Power << Powerspan << "|   " << Run << Runspan << "|   "
         << Sholder << Sholderspan << "|   " << Protect << Protectspan << "|   "
         << Catching << Catchingspan << "||" << endl;
    cout << "| -------------------------------------------------------------- |"
         << endl;
    cout << " ================================================================"
         << endl;

    cout << "[経験値割り振り]" << endl;
    cout << " ======================================================= " << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "||                         | 筋力 | 敏捷 | 技術 | 精神 ||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "||    現在の経験点    | -> |" << musclespan << muscle << " |"
         << agilespan << agile << " |" << techniquespan << technique << " |"
         << spiritspan << spirit << " ||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [1]    [ 弾道 ]    | ↑  |";
    Batter_Trajectory_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [2]    [ミート]    | ↑  |";
    Batter_Meet_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [3]    [パワー]    | ↑  |";
    Batter_Power_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [4]    [ 走力 ]    | ↑  |";
    Batter_Run_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [5]    [ 肩力 ]    | ↑  |";
    Batter_Sholder_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [6]    [守備力]    | ↑  |";
    Batter_Protect_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << "|| [7]    [ 捕球 ]    | ↑  |";
    Batter_Catching_decide();
    cout << "||" << endl;
    cout << "| ----------------------------------------------------- |" << endl;
    cout << " ======================================================= " << endl;
    cout << "どの能力を上げますか？ ▼ " << endl;
    cout << "[[能力番号]] -> [1 ~ 7]" << endl;
    cout << "[[能力決定]] -> [9]" << endl;
    cout << "[[キャンセル]] -> [0]" << endl;
    cout << "選択 -> ";
    cin >> allocate_number;
    if(allocate_number == 9)
        return;
    if(allocate_number == 0) {

        //能力戻し
        Trajectory = Trajectory_keep;
        Meet = Meet_keep;
        Power = Power_keep;
        Run = Run_keep;
        Sholder = Sholder_keep;
        Protect = Protect_keep;
        Catching = Catching_keep;

        //経験値戻し
        muscle = muscle_keep;
        agile = agile_keep;
        technique = technique_keep;
        spirit = spirit_keep;

        goto ALLOCATE_BATTER;
    }

    //--[弾道関係]------------------------------------------------------
    if(allocate_number == 1) {
        if(Trajectory == 4) {
            cout << "弾道値は最大に達しています ▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        int i = 0;
        while(1) {
            Trajectory_point();
            if((muscle < 0) || (technique < 0) || (spirit < 0) ||
               (Trajectory == 4)) {
                if(Trajectory == Trajectory_keep) {
                    if(getchar() == '\n')
                        cout << "弾道値はあげられません。▼ ";
                    muscle = muscle_keep;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_BATTER;
                }
                cout << "弾道値は現在" << Trajectory
                     << "まで上げることができます。▼ " << endl;
                muscle = muscle_keep;
                technique = technique_keep;
                spirit = spirit_keep;
                Trajectory = Trajectory_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "弾道値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Trajectory_p;
        if(Trajectory_p == 0)
            goto ALLOCATE_BATTER;
        Trajectory_p = Trajectory_p - Trajectory;
        if(Trajectory_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        while(1) {
            i++;
            Trajectory_point();
            if((muscle < 0) || (technique < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                muscle = muscle_keep;
                technique = technique_keep;
                spirit = spirit_keep;
                Trajectory = Trajectory_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_BATTER;
            } // if
            if(i == Trajectory_p)
                break;
        } // while
        goto ALLOCATE_BATTER;
    }

    //--[ミート関係]------------------------------------------------------
    if(allocate_number == 2) {
        if(Meet == 100) {
            cout << "ミート値は最大に達しています ▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        int i = 0;
        while(1) {
            Meet_point();
            if((muscle < 0) || (technique < 0) || (spirit < 0) ||
               (Meet == 100)) {
                if(Meet == Meet_keep) {
                    if(getchar() == '\n')
                        cout << "ミート値はあげられません。▼ " << endl;
                    muscle = muscle_keep;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_BATTER;
                }
                cout << "ミート値は現在" << Meet
                     << "まで上げることができます。▼ " << endl;
                muscle = muscle_keep;
                technique = technique_keep;
                spirit = spirit_keep;
                Meet = Meet_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "ミート値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Meet_p;
        if(Meet_p == 0)
            goto ALLOCATE_BATTER;
        Meet_p = Meet_p - Meet;
        if(Meet_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        while(1) {
            i++;
            Meet_point();
            if((muscle < 0) || (technique < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                muscle = muscle_keep;
                technique = technique_keep;
                spirit = spirit_keep;
                Meet = Meet_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_BATTER;
            }
            if(i == Meet_p)
                break;
        }
        goto ALLOCATE_BATTER;
    }

    //--[パワー関係]------------------------------------------------------
    if(allocate_number == 3) {
        if(Power == 100) {
            cout << "パワー値は最大に達しています ▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        int i = 0;
        while(1) {
            Power_point();
            if((muscle < 0) || (technique < 0) || (Power == 100)) {
                if(Power == Power_keep) {
                    if(getchar() == '\n')
                        cout << "パワー値はあげられません。▼ " << endl;
                    muscle = muscle_keep;
                    technique = technique_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_BATTER;
                }
                cout << "パワー値は現在" << Power
                     << "まで上げることができます。▼ " << endl;
                muscle = muscle_keep;
                technique = technique_keep;
                Power = Power_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "パワー値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Power_p;
        if(Power_p == 0)
            goto ALLOCATE_BATTER;
        Power_p = Power_p - Power;
        if(Power_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        while(1) {
            i++;
            Power_point();
            if((muscle < 0) || (technique < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                muscle = muscle_keep;
                technique = technique_keep;
                Power = Power_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_BATTER;
            }
            if(i == Power_p)
                break;
        }
        goto ALLOCATE_BATTER;
    }

    //--[走力関係]------------------------------------------------------
    if(allocate_number == 4) {
        if(Run == 100) {
            cout << "走力値は最大に達しています ▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        int i = 0;
        while(1) {
            Run_point();
            if((muscle < 0) || (agile < 0) || (Run == 100)) {
                if(Run == Run_keep) {
                    if(getchar() == '\n')
                        cout << "走力値はあげられません。▼ " << endl;
                    muscle = muscle_keep;
                    agile = agile_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_BATTER;
                }
                cout << "走力値は現在" << Run << "まで上げることができます。▼ "
                     << endl;
                muscle = muscle_keep;
                agile = agile_keep;
                Run = Run_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "走力値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Run_p;
        if(Run_p == 0)
            goto ALLOCATE_BATTER;
        Run_p = Run_p - Run;
        if(Run_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        while(1) {
            i++;
            Run_point();
            if((muscle < 0) || (agile < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                muscle = muscle_keep;
                agile = agile_keep;
                Run = Run_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_BATTER;
            }
            if(i == Run_p)
                break;
        }
        goto ALLOCATE_BATTER;
    }

    //--[肩力関係]------------------------------------------------------
    if(allocate_number == 5) {
        if(Sholder == 100) {
            cout << "肩力値は最大に達しています ▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        int i = 0;
        while(1) {
            Sholder_point();
            if((muscle < 0) || (agile < 0) || (technique < 0) ||
               (Sholder == 100)) {
                if(Sholder == Sholder_keep) {
                    if(getchar() == '\n')
                        cout << "肩力値はあげられません。▼ " << endl;
                    muscle = muscle_keep;
                    agile = agile_keep;
                    technique = technique_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_BATTER;
                }
                cout << "肩力値は現在" << Sholder
                     << "まで上げることができます。▼ " << endl;
                muscle = muscle_keep;
                agile = agile_keep;
                technique = technique_keep;
                Sholder = Sholder_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "肩力値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Sholder_p;
        if(Sholder_p == 0)
            goto ALLOCATE_BATTER;
        Sholder_p = Sholder_p - Sholder;
        if(Sholder_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        while(1) {
            i++;
            Sholder_point();
            if((muscle < 0) || (agile < 0) || (technique < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                muscle = muscle_keep;
                agile = agile_keep;
                technique = technique_keep;
                Sholder = Sholder_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_BATTER;
            }
            if(i == Sholder_p)
                break;
        }
        goto ALLOCATE_BATTER;
    }

    //--[守備力関係]------------------------------------------------------
    if(allocate_number == 6) {
        if(Protect == 100) {
            cout << "守備力値は最大に達しています ▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        int i = 0;
        while(1) {
            Protect_point();
            if((agile < 0) || (technique < 0) || (spirit < 0) ||
               (Protect == 100)) {
                if(Protect == Protect_keep) {
                    if(getchar() == '\n')
                        cout << "守備力値はあげられません。▼ " << endl;
                    agile = agile_keep;
                    technique = technique_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_BATTER;
                }
                cout << "守備力値は現在" << Protect
                     << "まで上げることができます。▼ " << endl;
                agile = agile_keep;
                technique = technique_keep;
                spirit = spirit_keep;
                Protect = Protect_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "守備力値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Protect_p;
        if(Protect_p == 0)
            goto ALLOCATE_BATTER;
        Protect_p = Protect_p - Protect;
        if(Protect_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        while(1) {
            i++;
            Protect_point();
            if((agile < 0) || (technique < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                agile = agile_keep;
                technique = technique_keep;
                spirit = spirit_keep;
                Protect = Protect_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_BATTER;
            }
            if(i == Protect_p)
                break;
        }
        goto ALLOCATE_BATTER;
    }

    //--[捕球関係]------------------------------------------------------
    if(allocate_number == 7) {
        if(Catching == 100) {
            cout << "捕球値は最大に達しています ▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        int i = 0;
        while(1) {
            Catching_point();
            if((agile < 0) || (spirit < 0) || (Catching == 100)) {
                if(Catching == Catching_keep) {
                    if(getchar() == '\n')
                        cout << "捕球値はあげられません。▼ " << endl;
                    agile = agile_keep;
                    spirit = spirit_keep;
                    if(getchar() == '\n')
                        goto ALLOCATE_BATTER;
                }
                cout << "捕球値は現在" << Catching
                     << "まで上げることができます。▼ " << endl;
                agile = agile_keep;
                spirit = spirit_keep;
                Catching = Catching_keep;
                break;
            } // if
        }     // while
        if(getchar() == '\n')
            cout << "捕球値をいくつまで上げますか？ ▼ " << endl;
        cout << "[[能力UP]] -> [目標ステータス値]" << endl;
        cout << "[[キャンセル]] -> [0]" << endl;
        cout << "入力 -> ";
        cin >> Catching_p;
        if(Catching_p == 0)
            goto ALLOCATE_BATTER;
        Catching_p = Catching_p - Catching;
        if(Catching_p <= 0) {
            cout << "現能力値以下なのはまずいですよ！▼ " << endl;
            goto ALLOCATE_BATTER;
        }
        while(1) {
            i++;
            Catching_point();
            if((agile < 0) || (spirit < 0)) {
                if(getchar() == '\n')
                    cout << "経験値が足りないゾ　▼ ";
                agile = agile_keep;
                spirit = spirit_keep;
                Catching = Catching_keep;
                if(getchar() == '\n')
                    goto ALLOCATE_BATTER;
            }
            if(i == Catching_p)
                break;
        }
        goto ALLOCATE_BATTER;
    }
}

void Trajectory_point(void) {
    //-----[弾道ポイント判定]-----------------------------------------
    if(Trajectory == 3) {
        muscle -= 50 * genius_point;
        if(muscle < 0)
            return;
        technique -= 50 * genius_point;
        if(technique < 0)
            return;
        spirit -= 50 * genius_point;
        if(spirit < 0)
            return;
        Trajectory++;
    }
    if(Trajectory == 2) {
        muscle -= 30 * genius_point;
        if(muscle < 0)
            return;
        technique -= 30 * genius_point;
        if(technique < 0)
            return;
        spirit -= 30 * genius_point;
        if(spirit < 0)
            return;
        Trajectory++;
    }
    if(Trajectory == 1) {
        muscle -= 10 * genius_point;
        if(muscle < 0)
            return;
        technique -= 10 * genius_point;
        if(technique < 0)
            return;
        spirit -= 10 * genius_point;
        if(spirit < 0)
            return;
        Trajectory++;
    }
}

void Meet_point(void) {
    //-----[ミートポイント判定]---------------------------------------
    if((Meet >= 90) && (Meet < 100)) {
        muscle -= 5 * genius_point;
        if(muscle < 0)
            return;
        technique -= 18 * genius_point;
        if(technique < 0)
            return;
        spirit -= 14 * genius_point;
        if(spirit < 0)
            return;
        Meet++;
    }
    if((Meet >= 80) && (Meet < 90)) {
        muscle -= 4 * genius_point;
        if(muscle < 0)
            return;
        technique -= 17 * genius_point;
        if(technique < 0)
            return;
        spirit -= 13 * genius_point;
        if(spirit < 0)
            return;
        Meet++;
    }
    if((Meet >= 70) && (Meet < 80)) {
        muscle -= 4 * genius_point;
        if(muscle < 0)
            return;
        technique -= 16 * genius_point;
        if(technique < 0)
            return;
        spirit -= 12 * genius_point;
        if(spirit < 0)
            return;
        Meet++;
    }
    if((Meet >= 60) && (Meet < 70)) {
        muscle -= 3 * genius_point;
        if(muscle < 0)
            return;
        technique -= 14 * genius_point;
        if(technique < 0)
            return;
        spirit -= 11 * genius_point;
        if(spirit < 0)
            return;
        Meet++;
    }
    if((Meet >= 50) && (Meet < 60)) {
        muscle -= 3 * genius_point;
        if(muscle < 0)
            return;
        technique -= 12 * genius_point;
        if(technique < 0)
            return;
        spirit -= 9 * genius_point;
        if(spirit < 0)
            return;
        Meet++;
    }
    if((Meet >= 40) && (Meet < 50)) {
        muscle -= 2 * genius_point;
        if(muscle < 0)
            return;
        technique -= 10 * genius_point;
        if(technique < 0)
            return;
        spirit -= 8 * genius_point;
        if(spirit < 0)
            return;
        Meet++;
    }
    if((Meet >= 20) && (Meet < 40)) {
        muscle -= 2 * genius_point;
        if(muscle < 0)
            return;
        technique -= 8 * genius_point;
        if(technique < 0)
            return;
        spirit -= 6 * genius_point;
        if(spirit < 0)
            return;
        Meet++;
    }
    if(Meet < 20) {
        muscle -= 1;
        if(muscle < 0)
            return;
        technique -= 6 * genius_point;
        if(technique < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Meet++;
    }
}

void Power_point(void) {
    //-----[パワーポイント判定]---------------------------------------
    if((Power >= 90) && (Power < 100)) {
        muscle -= 30 * genius_point;
        if(muscle < 0)
            return;
        technique -= 10 * genius_point;
        if(technique < 0)
            return;
        Power++;
    }
    if((Power >= 80) && (Power < 90)) {
        muscle -= 27 * genius_point;
        if(muscle < 0)
            return;
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        Power++;
    }
    if((Power >= 70) && (Power < 80)) {
        muscle -= 24 * genius_point;
        if(muscle < 0)
            return;
        technique -= 8 * genius_point;
        if(technique < 0)
            return;
        Power++;
    }
    if((Power >= 60) && (Power < 70)) {
        muscle -= 21 * genius_point;
        if(muscle < 0)
            return;
        technique -= 7 * genius_point;
        if(technique < 0)
            return;
        Power++;
    }
    if((Power >= 50) && (Power < 60)) {
        muscle -= 18 * genius_point;
        if(muscle < 0)
            return;
        technique -= 6 * genius_point;
        if(technique < 0)
            return;
        Power++;
    }
    if((Power >= 40) && (Power < 50)) {
        muscle -= 15 * genius_point;
        if(muscle < 0)
            return;
        technique -= 5 * genius_point;
        if(technique < 0)
            return;
        Power++;
    }
    if((Power >= 20) && (Power < 40)) {
        muscle -= 12 * genius_point;
        if(muscle < 0)
            return;
        technique -= 4 * genius_point;
        if(technique < 0)
            return;
        Power++;
    }
    if(Power < 20) {
        muscle -= 10 * genius_point;
        if(muscle < 0)
            return;
        technique -= 2 * genius_point;
        if(technique < 0)
            return;
        Power++;
    }
}

void Run_point(void) {
    //-----[走力ポイント判定]-----------------------------------------
    if((Run >= 90) && (Run < 100)) {
        muscle -= 5 * genius_point;
        if(muscle < 0)
            return;
        agile -= 20 * genius_point;
        if(muscle < 0)
            return;
        Run++;
    }
    if((Run >= 80) && (Run < 90)) {
        muscle -= 4 * genius_point;
        if(muscle < 0)
            return;
        agile -= 20 * genius_point;
        if(muscle < 0)
            return;
        Run++;
    }
    if((Run >= 70) && (Run < 80)) {
        muscle -= 4 * genius_point;
        if(muscle < 0)
            return;
        agile -= 18 * genius_point;
        if(muscle < 0)
            return;
        Run++;
    }
    if((Run >= 60) && (Run < 70)) {
        muscle -= 3 * genius_point;
        if(muscle < 0)
            return;
        agile -= 16 * genius_point;
        if(muscle < 0)
            return;
        Run++;
    }
    if((Run >= 50) && (Run < 60)) {
        muscle -= 3 * genius_point;
        if(muscle < 0)
            return;
        agile -= 14 * genius_point;
        if(muscle < 0)
            return;
        Run++;
    }
    if((Run >= 40) && (Run < 50)) {
        muscle -= 2 * genius_point;
        if(muscle < 0)
            return;
        agile -= 12 * genius_point;
        if(muscle < 0)
            return;
        Run++;
    }
    if((Run >= 20) && (Run < 40)) {
        muscle -= 2 * genius_point;
        if(muscle < 0)
            return;
        agile -= 10 * genius_point;
        if(muscle < 0)
            return;
        Run++;
    }
    if(Run < 20) {
        muscle -= 1;
        if(muscle < 0)
            return;
        agile -= 8 * genius_point;
        if(muscle < 0)
            return;
        Run++;
    }
}

void Sholder_point(void) {
    //-----[肩力ポイント判定]-----------------------------------------
    if((Sholder >= 90) && (Sholder < 100)) {
        muscle -= 9 * genius_point;
        if(muscle < 0)
            return;
        agile -= 9 * genius_point;
        if(agile < 0)
            return;
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        Sholder++;
    }
    if((Sholder >= 80) && (Sholder < 90)) {
        muscle -= 9 * genius_point;
        if(muscle < 0)
            return;
        agile -= 9 * genius_point;
        if(agile < 0)
            return;
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        Sholder++;
    }
    if((Sholder >= 70) && (Sholder < 80)) {
        muscle -= 8 * genius_point;
        if(muscle < 0)
            return;
        agile -= 8 * genius_point;
        if(agile < 0)
            return;
        technique -= 8 * genius_point;
        if(technique < 0)
            return;
        Sholder++;
    }
    if((Sholder >= 60) && (Sholder < 70)) {
        muscle -= 7 * genius_point;
        if(muscle < 0)
            return;
        agile -= 7 * genius_point;
        if(agile < 0)
            return;
        technique -= 7 * genius_point;
        if(technique < 0)
            return;
        Sholder++;
    }
    if((Sholder >= 50) && (Sholder < 60)) {
        muscle -= 6 * genius_point;
        if(muscle < 0)
            return;
        agile -= 6 * genius_point;
        if(agile < 0)
            return;
        technique -= 6 * genius_point;
        if(technique < 0)
            return;
        Sholder++;
    }
    if((Sholder >= 40) && (Sholder < 50)) {
        muscle -= 5 * genius_point;
        if(muscle < 0)
            return;
        agile -= 5 * genius_point;
        if(agile < 0)
            return;
        technique -= 5 * genius_point;
        if(technique < 0)
            return;
        Sholder++;
    }
    if((Sholder >= 20) && (Sholder < 40)) {
        muscle -= 4 * genius_point;
        if(muscle < 0)
            return;
        agile -= 4 * genius_point;
        if(agile < 0)
            return;
        technique -= 4 * genius_point;
        if(technique < 0)
            return;
        Sholder++;
    }
    if(Sholder < 20) {
        muscle -= 3 * genius_point;
        if(muscle < 0)
            return;
        agile -= 3 * genius_point;
        if(agile < 0)
            return;
        technique -= 3 * genius_point;
        if(technique < 0)
            return;
        Sholder++;
    }
}

void Protect_point(void) {
    //-----[守備力ポイント判定]-----------------------------------------
    if((Protect >= 90) && (Protect < 100)) {
        agile -= 9 * genius_point;
        if(agile < 0)
            return;
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        spirit -= 9 * genius_point;
        if(spirit < 0)
            return;
        Protect++;
    }
    if((Protect >= 80) && (Protect < 90)) {
        agile -= 9 * genius_point;
        if(agile < 0)
            return;
        technique -= 9 * genius_point;
        if(technique < 0)
            return;
        spirit -= 9 * genius_point;
        if(spirit < 0)
            return;
        Protect++;
    }
    if((Protect >= 70) && (Protect < 80)) {
        agile -= 8 * genius_point;
        if(agile < 0)
            return;
        technique -= 8 * genius_point;
        if(technique < 0)
            return;
        spirit -= 8 * genius_point;
        if(spirit < 0)
            return;
        Protect++;
    }
    if((Protect >= 60) && (Protect < 70)) {
        agile -= 7 * genius_point;
        if(agile < 0)
            return;
        technique -= 7 * genius_point;
        if(technique < 0)
            return;
        spirit -= 7 * genius_point;
        if(spirit < 0)
            return;
        Protect++;
    }
    if((Protect >= 50) && (Protect < 60)) {
        agile -= 6 * genius_point;
        if(agile < 0)
            return;
        technique -= 6 * genius_point;
        if(technique < 0)
            return;
        spirit -= 6 * genius_point;
        if(spirit < 0)
            return;
        Protect++;
    }
    if((Protect >= 40) && (Protect < 50)) {
        agile -= 5 * genius_point;
        if(agile < 0)
            return;
        technique -= 5 * genius_point;
        if(technique < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Protect++;
    }
    if((Protect >= 20) && (Protect < 40)) {
        agile -= 4 * genius_point;
        if(agile < 0)
            return;
        technique -= 4 * genius_point;
        if(technique < 0)
            return;
        spirit -= 4 * genius_point;
        if(spirit < 0)
            return;
        Protect++;
    }
    if(Protect < 20) {
        agile -= 3 * genius_point;
        if(agile < 0)
            return;
        technique -= 3 * genius_point;
        if(technique < 0)
            return;
        spirit -= 3 * genius_point;
        if(spirit < 0)
            return;
        Protect++;
    }
}

void Catching_point(void) {
    //-----[捕球ポイント判定]-----------------------------------------
    if((Catching >= 90) && (Catching) < 100) {
        agile -= 5 * genius_point;
        if(agile < 0)
            return;
        spirit -= 12 * genius_point;
        if(spirit < 0)
            return;
        Catching++;
    }
    if((Catching >= 80) && (Catching < 90)) {
        agile -= 5 * genius_point;
        if(agile < 0)
            return;
        spirit -= 11 * genius_point;
        if(spirit < 0)
            return;
        Catching++;
    }
    if((Catching >= 70) && (Catching < 80)) {
        agile -= 4 * genius_point;
        if(agile < 0)
            return;
        spirit -= 10 * genius_point;
        if(spirit < 0)
            return;
        Catching++;
    }
    if((Catching >= 60) && (Catching < 70)) {
        agile -= 4 * genius_point;
        if(agile < 0)
            return;
        spirit -= 9 * genius_point;
        if(spirit < 0)
            return;
        Catching++;
    }
    if((Catching >= 50) && (Catching < 60)) {
        agile -= 3 * genius_point;
        if(agile < 0)
            return;
        spirit -= 8 * genius_point;
        if(spirit < 0)
            return;
        Catching++;
    }
    if((Catching >= 40) && (Catching < 50)) {
        agile -= 3 * genius_point;
        if(agile < 0)
            return;
        spirit -= 7 * genius_point;
        if(spirit < 0)
            return;
        Catching++;
    }
    if((Catching >= 20) && (Catching < 40)) {
        agile -= 2 * genius_point;
        if(agile < 0)
            return;
        spirit -= 6 * genius_point;
        if(spirit < 0)
            return;
        Catching++;
    }
    if(Catching < 20) {
        agile -= 2 * genius_point;
        if(agile < 0)
            return;
        spirit -= 5 * genius_point;
        if(spirit < 0)
            return;
        Catching++;
    }
}

void Pitcher_status(void) {

    //-----[投手ステータス]------------------------------------------------------------
    Pitcher_status_decide();

    //各投手能力値の長さ判定
    if((Control >= 0) && (Control < 10))
        length_Control = 1;
    else if((Control >= 10) && (Control < 100))
        length_Control = 2;
    else
        length_Control = 3;

    if((Stamina >= 0) && (Stamina < 10))
        length_Stamina = 1;
    else if((Stamina >= 10) && (Stamina < 100))
        length_Stamina = 2;
    else
        length_Stamina = 3;

    if((Ball >= 0) && (Ball < 10))
        length_Ball = 1;
    else if((Ball >= 10) && (Ball < 100))
        length_Ball = 2;
    else
        length_Ball = 3;

    //野手能力画面の空白調節部分
    string Controlspan(4 - length_Control, ' ');
    string Staminaspan(4 - length_Stamina, ' ');
    string Ballspan(4 - length_Ball, ' ');

    system("clear");
    cout << "[[大会" << days << "日前]]" << endl;
    cout << "[名前] : " << Name << "   [投手][" << Number << "]" << endl;

    if(Hp > 0) {
        cout << "[体力] : " << Hp << "/" << HP << endl;
        cout << " ============================================================="
                "===="
                "========="
             << endl;
        cout << "| "
                "--------------------------------------------------------------"
                "----"
                "------ |"
             << endl;
        cout << "||       シュート                 スライダー                  "
                "    "
                "        ||"
             << endl;
        cout << "|| ";
        Shoot_7(Shoot_status);
        Shoot_6(Shoot_status);
        Shoot_5(Shoot_status);
        Shoot_4(Shoot_status);
        Shoot_3(Shoot_status);
        Shoot_2(Shoot_status);
        Shoot_1(Shoot_status);
        cout << "[@]";
        Slider_1(Slider_status);
        Slider_2(Slider_status);
        Slider_3(Slider_status);
        Slider_4(Slider_status);
        Slider_5(Slider_status);
        Slider_6(Slider_status);
        Slider_7(Slider_status);
        cout << "  ======================  ||" << endl;
        cout << "||                   ";
        Sinker_1(Sinker_status);
        Fork_1(Fork_status);
        Curve_1(Curve_status);
        cout << "                   |    球速    |" << Ballspan << Ball
             << "km/h | ||" << endl;
        cout << "||                ";
        Sinker_2(Sinker_status);
        cout << "   ";
        Fork_2(Fork_status);
        cout << "   ";
        Curve_2(Curve_status);
        cout << "                |----------------------| ||" << endl;
        cout << "||   シンカー  ";
        Sinker_3(Sinker_status);
        cout << "      ";
        Fork_3(Fork_status);
        cout << "      ";
        Curve_3(Curve_status);
        cout << "  カーブ";
        cout << "     |コントロール|「";
        Control_color(Control_status);
        cout << "」" << Control << Controlspan << "| ||" << endl;
        cout << "||          ";
        Sinker_4(Sinker_status);
        cout << "         ";
        Fork_4(Fork_status);
        cout << "         ";
        Curve_4(Curve_status);
        cout << "          |----------------------| ||" << endl;
        cout << "||       ";
        Sinker_5(Sinker_status);
        cout << "            ";
        Fork_5(Fork_status);
        cout << "            ";
        Curve_5(Curve_status);
        cout << "       |  スタミナ  |「";
        Stamina_color(Stamina_status);
        cout << "」" << Stamina << Staminaspan << "| ||" << endl;
        cout << "||    ";
        Sinker_6(Sinker_status);
        cout << "               ";
        Fork_6(Fork_status);
        cout << "               ";
        Curve_6(Curve_status);
        cout << "     ======================  ||" << endl;
        cout << "|| ";
        Sinker_7(Sinker_status);
        cout << "                  ";
        Fork_7(Fork_status);
        cout << "                  ";
        Curve_7(Curve_status);
        cout << "                          ||" << endl;
        cout << "||                   フォーク                                 "
                "    "
                "        ||"
             << endl;
        cout << "| "
                "--------------------------------------------------------------"
                "----"
                "------ |"
             << endl;
        cout << " ============================================================="
                "===="
                "========="
             << endl;
    } else {
        Hp = 0;
        cout << "[体力] : " << Hp << "/" << HP << endl;
    }
}

void Batter_status(void) {

    //-----[野手ステータス]------------------------------------------------------------
    Batter_status_decide();

    //各野手能力値の長さ判定
    if((Meet >= 0) && (Meet < 10))
        length_Meet = 1;
    else if((Meet >= 10) && (Meet < 100))
        length_Meet = 2;
    else
        length_Meet = 3;

    if((Power >= 0) && (Power < 10))
        length_Power = 1;
    else if((Power >= 10) && (Power < 100))
        length_Power = 2;
    else
        length_Power = 3;

    if((Run >= 0) && (Run < 10))
        length_Run = 1;
    else if((Run >= 10) && (Run < 100))
        length_Run = 2;
    else
        length_Run = 3;

    if((Sholder >= 0) && (Sholder < 10))
        length_Sholder = 1;
    else if((Sholder >= 10) && (Sholder < 100))
        length_Sholder = 2;
    else
        length_Sholder = 3;

    if((Protect >= 0) && (Protect < 10))
        length_Protect = 1;
    else if((Protect >= 10) && (Protect < 100))
        length_Protect = 2;
    else
        length_Protect = 3;

    if((Catching >= 0) && (Catching < 10))
        length_Catching = 1;
    else if((Catching >= 10) && (Catching < 100))
        length_Catching = 2;
    else
        length_Catching = 3;

    //野手能力画面の空白調節部分
    string Meetspan(5 - length_Meet, ' ');
    string Powerspan(5 - length_Power, ' ');
    string Runspan(5 - length_Run, ' ');
    string Sholderspan(5 - length_Sholder, ' ');
    string Protectspan(5 - length_Protect, ' ');
    string Catchingspan(5 - length_Catching, ' ');
    //ポジション名空白作り
    int length_position_span = 0;
    if(Position == 2)
        length_position_span = 1;
    string Positionspan(length_position_span, ' ');

    system("clear");
    cout << "[[大会" << days << "日前]]" << endl;
    cout << "[名前] : " << Name << "   [" << Position_name << "][" << Number
         << "]" << endl;
    cout << " ================================================================"
         << endl;
    cout << "| -------------------------------------------------------------- |"
         << endl;
    cout << "|| [弾道] |[ミート]|[パワー]| [走力] | [肩力] |[守備力]| [捕球] ||"
         << endl;
    cout << "||--------------------------------------------------------------||"
         << endl;
    cout << "||    ";
    Trajectory_color(Trajectory_status);
    cout << "   |   ";
    Meet_color(Meet_status);
    cout << "    |   ";
    Power_color(Power_status);
    cout << "    |   ";
    Run_color(Run_status);
    cout << "    |   ";
    Sholder_color(Sholder_status);
    cout << "    |   ";
    Protect_color(Protect_status);
    cout << "    |   ";
    Catching_color(Catching_status);
    cout << "    ||" << endl;
    cout << "||--------------------------------------------------------------||"
         << endl;
    cout << "||    " << Trajectory_status << "   |   " << Meet << Meetspan
         << "|   " << Power << Powerspan << "|   " << Run << Runspan << "|   "
         << Sholder << Sholderspan << "|   " << Protect << Protectspan << "|   "
         << Catching << Catchingspan << "||" << endl;
    cout << "| -------------------------------------------------------------- |"
         << endl;
    cout << " ================================================================"
         << endl;
}

void Feeling(void) {
    if(condition == 1)
        cout << "| [[絶不調]]"
             << "\x1b[34m"
             << " (T T)♩"
             << "\x1b[39m"
             << "    |" << endl;
    if(condition == 2)
        cout << "|  [[不調]] "
             << "\x1b[36m"
             << "(- -)♩♩"
             << "\x1b[39m"
             << "    |" << endl;
    if(condition == 3)
        cout << "|  [[普通]] "
             << "\x1b[33m"
             << "(・・)♩♩♩"
             << "\x1b[39m"
             << "  |" << endl;
    if(condition == 4)
        cout << "|  [[好調]] "
             << "\x1b[31m"
             << "(^ ^)♩♩♩♩"
             << "\x1b[39m"
             << "  |" << endl;
    if(condition == 5)
        cout << "| [[絶好調]]"
             << "\x1b[35m"
             << "(^∇^)♩♩♩♩♩"
             << "\x1b[39m"
             << " |" << endl;
}

void Daijyoubu_success(void) {
    cout << "                         ＊" << endl;
    cout << "                          ＊" << endl;
    cout << "                          ＊" << endl;
    cout << "                         ＊" << endl;
    cout << "                        ＊" << endl;
    cout << "              ＊＊＊＊＊＊＊＊＊＊" << endl;
    cout << "         ＊                           ＊" << endl;
    cout << "       ＊    ＊          ＊             ＊" << endl;
    cout << "     ＊  ＊　 　＊    ＊  　 ＊         ＊＊" << endl;
    cout << "    ＊      ＊＊        ＊＊          ＊＊＊＊" << endl;
    cout << "  ＊＊   ＊　　　＊  ＊ 　　 ＊       ＊＊＊＊＊" << endl;
    cout << "  ＊＊＊＊　　　  ＊＊　    　＊＊＊＊＊＊＊＊＊" << endl;
    cout << "  ＊＊   ＊      ＊  ＊      ＊      ＊＊＊＊＊" << endl;
    cout << "    ＊      ＊＊        ＊＊     ＊＊   ＊＊＊" << endl;
    cout << "＊　   ＊                       ＊      ＊＊" << endl;
    cout << "   ＊＊＊＊                  ＊    ＊   ＊" << endl;
    cout << "      ＊＊＊              ＊＊＊＊      ＊" << endl;
    cout << "   ＊                                   ＊" << endl;
    cout << "   ＊                                   ＊" << endl;
    cout << "    ＊                                 ＊" << endl;
    cout << "      ＊                             ＊" << endl;
    cout << "         ＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
    cout << "           ＊ ＊   ＊  ＊  ＊＊  ＊" << endl;
    cout << "         ＊ ＊＊  ＊＊ ＊ ＊  ＊   ＊" << endl;
    cout << "       ＊ ＊ ＊  ＊ ＊ ＊  ＊  ＊   ＊" << endl;
    cout << "      ＊ ＊ ＊   ＊ ＊ ＊ ＊    ＊  ＊" << endl;
    cout << "      ＊＊＊      ＊＊ ＊＊      ＊ ＊" << endl;
    cout << endl;
}

void Daijyoubu_fail(void) {
    cout << "                         ＊" << endl;
    cout << "                          ＊" << endl;
    cout << "                          ＊" << endl;
    cout << "                         ＊" << endl;
    cout << "                        ＊" << endl;
    cout << "              ＊＊＊＊＊＊＊＊＊＊" << endl;
    cout << "         ＊                           ＊" << endl;
    cout << "       ＊     ＊       ＊               ＊" << endl;
    cout << "     ＊  ＊　 　         　 ＊          ＊＊" << endl;
    cout << "    ＊      ＊＊        ＊＊          ＊＊＊＊" << endl;
    cout << "  ＊＊   ＊　　　＊  ＊ 　　 ＊       ＊＊＊＊＊" << endl;
    cout << "  ＊＊＊＊　　　  ＊＊　    　＊＊＊＊＊＊＊＊＊" << endl;
    cout << "  ＊＊   ＊      ＊  ＊      ＊      ＊＊＊＊＊" << endl;
    cout << "    ＊      ＊＊        ＊＊     ＊＊   ＊＊＊" << endl;
    cout << "＊　   ＊                       ＊      ＊＊" << endl;
    cout << "   ＊＊＊＊                  ＊    ＊   ＊" << endl;
    cout << "      ＊＊＊              ＊＊＊＊      ＊" << endl;
    cout << "   ＊                                   ＊" << endl;
    cout << "   ＊                                   ＊" << endl;
    cout << "    ＊                                 ＊" << endl;
    cout << "      ＊                             ＊" << endl;
    cout << "         ＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
    cout << "           ＊ ＊   ＊  ＊  ＊＊  ＊" << endl;
    cout << "         ＊ ＊＊  ＊＊ ＊ ＊  ＊   ＊" << endl;
    cout << "       ＊ ＊ ＊  ＊ ＊ ＊  ＊  ＊   ＊" << endl;
    cout << "      ＊ ＊ ＊   ＊ ＊ ＊ ＊    ＊  ＊" << endl;
    cout << "      ＊＊＊      ＊＊ ＊＊      ＊ ＊" << endl;
    cout << endl;
}

void Pawapuro_normal(void) {
    cout << endl;
    cout << endl;
    cout << "         ＊＊＊＊＊＊＊  " << endl;
    cout << "   ＊                     ＊" << endl;
    cout << " ＊                         ＊" << endl;
    cout << "＊                           ＊" << endl;
    cout << "＊            　             ＊" << endl;
    cout << "＊                　 ＊      ＊" << endl;
    cout << "＊             ＊　　　　　　　　＊" << endl;
    cout << "＊           ＊                      ＊" << endl;
    cout << "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
    cout << " ＊        ＊  ＊＊  ＊＊  ＊＊" << endl;
    cout << " ＊        ＊  ＊＊  ＊＊  ＊＊" << endl;
    cout << " ＊        ＊  　＊  ＊    ＊＊" << endl;
    cout << " ＊         ＊＊＊    ＊＊＊  ＊" << endl;
    cout << " ＊                            ＊" << endl;
    cout << "  ＊                           ＊" << endl;
    cout << "     ＊                       ＊" << endl;
    cout << "         ＊＊＊＊＊＊＊＊＊" << endl;
    cout << "           ＊ ＊     ＊＊" << endl;
    cout << "         ＊   ＊      ＊＊" << endl;
    cout << "        ＊    ＊       ＊＊" << endl;
    cout << "        ＊ ＊ ＊       ＊＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "        ＊   ＊          ＊" << endl;
    cout << endl;
}

void Pawapuro_happy(void) {
    cout << endl;
    cout << endl;
    cout << "         ＊＊＊＊＊＊＊  " << endl;
    cout << "   ＊                     ＊" << endl;
    cout << " ＊                         ＊" << endl;
    cout << "＊                           ＊" << endl;
    cout << "＊            　             ＊" << endl;
    cout << "＊                　 ＊      ＊" << endl;
    cout << "＊             ＊　　　　　　　　＊" << endl;
    cout << "＊           ＊                      ＊" << endl;
    cout << "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
    cout << " ＊         ＊＊   　 ＊＊ 　＊" << endl;
    cout << " ＊      ＊ 　　＊ 　＊   ＊ ＊" << endl;
    cout << " ＊     ＊　　　 ＊ ＊　　 ＊＊" << endl;
    cout << " ＊                           ＊" << endl;
    cout << " ＊                            ＊" << endl;
    cout << "  ＊                           ＊" << endl;
    cout << "     ＊                       ＊" << endl;
    cout << "         ＊＊＊＊＊＊＊＊＊" << endl;
    cout << "           ＊ ＊     ＊＊" << endl;
    cout << "         ＊   ＊      ＊＊" << endl;
    cout << "        ＊    ＊       ＊＊" << endl;
    cout << "      　＊ ＊ ＊       ＊＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "        ＊   ＊          ＊" << endl;
    cout << endl;
}

void Pawapuro_surprise(void) {
    cout << endl;
    cout << endl;
    cout << "         ＊＊＊＊＊＊＊  " << endl;
    cout << "   ＊                     ＊" << endl;
    cout << " ＊                         ＊" << endl;
    cout << "＊                           ＊" << endl;
    cout << "＊            　             ＊" << endl;
    cout << "＊                　 ＊      ＊" << endl;
    cout << "＊             ＊　　　　　　　　＊" << endl;
    cout << "＊         　＊＊      ＊＊           ＊" << endl;
    cout << "＊＊＊＊ ＊  　　 ＊＊　     ＊＊＊＊＊" << endl;
    cout << " ＊      ＊  　＊ ＊＊　 ＊  ＊" << endl;
    cout << " ＊      ＊  　　 ＊＊　 　　＊" << endl;
    cout << " ＊        　＊＊　　　＊＊　＊" << endl;
    cout << " ＊                           ＊" << endl;
    cout << " ＊                            ＊" << endl;
    cout << "  ＊                           ＊" << endl;
    cout << "     ＊                       ＊" << endl;
    cout << "         ＊＊＊＊＊＊＊＊＊" << endl;
    cout << "           ＊ ＊     ＊＊" << endl;
    cout << "         ＊   ＊      ＊＊" << endl;
    cout << "        ＊    ＊       ＊＊" << endl;
    cout << "        ＊ ＊ ＊       ＊＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "        ＊   ＊          ＊" << endl;
    cout << endl;
}

void Pawapuro_sad(void) {
    cout << endl;
    cout << endl;
    cout << "         ＊＊＊＊＊＊＊  " << endl;
    cout << "   ＊                     ＊" << endl;
    cout << " ＊                         ＊" << endl;
    cout << "＊                           ＊" << endl;
    cout << "＊            　             ＊" << endl;
    cout << "＊                　 ＊      ＊" << endl;
    cout << "＊             ＊　　　　　　　　＊" << endl;
    cout << "＊           ＊                      ＊" << endl;
    cout << "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
    cout << " ＊          　＊＊  ＊＊    ＊" << endl;
    cout << " ＊        ＊  ＊＊  ＊＊ ＊ ＊" << endl;
    cout << " ＊      ＊ ＊   ＊  ＊    ＊＊" << endl;
    cout << " ＊         ＊＊＊    ＊＊＊  ＊" << endl;
    cout << " ＊                            ＊" << endl;
    cout << "  ＊                           ＊" << endl;
    cout << "     ＊                       ＊" << endl;
    cout << "         ＊＊＊＊＊＊＊＊＊" << endl;
    cout << "           ＊ ＊     ＊＊" << endl;
    cout << "         ＊   ＊      ＊＊" << endl;
    cout << "        ＊    ＊       ＊＊" << endl;
    cout << "        ＊ ＊ ＊       ＊＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "        ＊   ＊          ＊" << endl;
    cout << endl;
}

void Pawapuro_angry(void) {
    cout << endl;
    cout << endl;
    cout << "         ＊＊＊＊＊＊＊  " << endl;
    cout << "   ＊                     ＊" << endl;
    cout << " ＊                         ＊" << endl;
    cout << "＊                           ＊" << endl;
    cout << "＊            　             ＊" << endl;
    cout << "＊                　 ＊      ＊" << endl;
    cout << "＊        ＊   ＊　　　    　＊　＊" << endl;
    cout << "＊          ＊             ＊        ＊" << endl;
    cout << "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
    cout << " ＊        ＊  ＊      ＊  ＊＊" << endl;
    cout << " ＊        ＊  ＊＊  ＊＊  ＊＊" << endl;
    cout << " ＊        ＊  　＊  ＊    ＊＊" << endl;
    cout << " ＊         ＊＊＊    ＊＊＊  ＊" << endl;
    cout << " ＊                            ＊" << endl;
    cout << "  ＊                           ＊" << endl;
    cout << "     ＊                       ＊" << endl;
    cout << "         ＊＊＊＊＊＊＊＊＊" << endl;
    cout << "           ＊ ＊     ＊＊" << endl;
    cout << "         ＊   ＊      ＊＊" << endl;
    cout << "        ＊    ＊       ＊＊" << endl;
    cout << "        ＊ ＊ ＊       ＊＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "      ＊       ＊ ＊＊＊  ＊" << endl;
    cout << "        ＊   ＊          ＊" << endl;
    cout << endl;
}
