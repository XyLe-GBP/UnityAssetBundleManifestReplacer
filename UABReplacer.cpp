// UABReplacer.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "Utils.h"

bool shapingUAB(unsigned int option, char* targetpath, char* outputpath)
{
    ifstream ifs(targetpath, ios::in | ios::binary);
    if (!ifs) {
        system("cls");
        printf_s("File: %s\n", targetpath);
        printf_s("ifstream failed to execute.\n");
        return EXIT_FAILURE;
    }

    ofstream ofs(outputpath, ios::out);
    if (!ofs) {
        system("cls");
        printf_s("File: %s\n", outputpath);
        printf_s("ofstream failed to execute.\n");
        return EXIT_FAILURE;
    }

    switch (option)
    {
    case 0:
    {
        ifs.seekg(0, SEEK_END);
        streamoff size = ifs.tellg();
        ifs.seekg(0, SEEK_SET);

        char* buffer_c_str = new char[(size_t)size];
        string original_buffer, regex_buffer_v1, regex_buffer_v2;
        vector<string> sorted_buffer;

        while (!ifs.eof()) {
            ifs.read(buffer_c_str, sizeof(buffer_c_str));
            original_buffer.append(buffer_c_str, (size_t)ifs.gcount());
            
        }
        ifs.close();
        delete[] buffer_c_str;

        printf_s("AssetBundle Mainfest is being reshaped... (1/23)");
        regex_buffer_v1 = regex_all(original_buffer, regex("[^a-z0-9\\._][^a-z0-9\\._]+"), "\"resource\": ");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (2/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex("[\"][^a-z0-9\\._\":\\s]+"), "");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (3/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex(".unity3d"), ".unity3d,\n--------------------\n");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (4/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex("\\xD90"), "\",\n\"index\": \"");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (5/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex("[a-z0-9][^a-z0-9\\._:\",\\+^\\s]+"), "");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (6/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex("[a-z0-9][a-z0-9][^a-z0-9\\._:\",\\+^\\s]+"), "");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (7/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex("[^a-z0-9\\n][a-z0-9][a-z0-9][^a-z0-9\\._:\",\\+^\\s]+"), "");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (8/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex("\\xCD"), "#");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (9/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex("#[a-z0-9]+"), "");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (10/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex("\"resource\": .\"resource\":"), "\"resource\": "); // Replace duplicate lines of text.

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (11/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex("^(?!.*unity3d).*(?=\"resource\": ).*$"), ""); // Deleted assetbundle hash.

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (12/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex("^(?!.*unity3d).*(?=\"resource\": ).*(?!.*[^a-z0-9]+).*$"), "");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (13/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex("^#.*:"), "\"resource\":");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (14/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex(" .*[:]"), "");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (15/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex("^\\..*:"), "\"resource\":");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (16/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex(".*[^a-z0-9\":,\\s\\n\\.\\+_-]+"), "\"resource\": ");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (17/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex("^_\""), "\"");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (18/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex("^_"), "\"resource\": ");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (19/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex("^\\."), "\"resource\": unknown_resource."); // Replace '.unity3d' only resource string with 'unknown_resource.unity3d'.

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (20/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex(" \\."), " ");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (21/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex("  "), " ");

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (22/23)");
        regex_buffer_v2 = regex_all(regex_buffer_v1, regex(": 0.unity3d"), ": dummy_resource.unity3d"); // Replace '0.unity3d' only resource string with 'dummy_resource.unity3d'.

        system("cls");
        printf_s("AssetBundle Mainfest is being reshaped... (23/23)");
        regex_buffer_v1 = regex_all(regex_buffer_v2, regex(": _"), ": ");

        system("cls");
        ofs << "Unity AssetBundle Manifest File\nShapaded by: UABMReplacer - version 1.0\n\nCopyright (C) 2021 - XyLe, All Rights Reserved.\n\n";
        ofs << regex_buffer_v1;
        ofs.close();

        //sortAll(outputpath, outputpath);

        system("cls");
        return EXIT_SUCCESS;
    }
    case 1:
    {
        ifs.seekg(0, SEEK_END);
        streamoff size = ifs.tellg();
        ifs.seekg(0, SEEK_SET);

        char* buffer_c_str = new char[(size_t)size];
        string original_buffer, regex_buffer_v1, regex_buffer_v2, user_input_v1, user_input_v2, user_cont;
        vector<string> sorted_buffer;

        while (!ifs.eof()) {
            ifs.read(buffer_c_str, sizeof(buffer_c_str));
            original_buffer.append(buffer_c_str, (size_t)ifs.gcount());

        }
        ifs.close();
        delete[] buffer_c_str;

        int lp = 0, ctd = 0, ct = 0;
        while (lp == 0) {
            printf_s("Enter a regular expression.\n>>");
            cin >> user_input_v1;
            system("cls");
            printf_s("Enter the string to be replaced when a match is made.\n>>");
            cin >> user_input_v2;
            system("cls");

            if (ct != 0) {
                if (ctd % 2 == 0) {
                    printf_s("AssetBundle Mainfest is being reshaped... \nPlease wait a moment.");
                    regex_buffer_v1 = regex_all(regex_buffer_v2, regex(user_input_v1), user_input_v2);
                }
                else {
                    printf_s("AssetBundle Mainfest is being reshaped... \nPlease wait a moment.");
                    regex_buffer_v2 = regex_all(regex_buffer_v1, regex(user_input_v1), user_input_v2);
                }
                ctd++;
            }
            else {
                printf_s("AssetBundle Mainfest is being reshaped... \nPlease wait a moment.");
                regex_buffer_v1 = regex_all(original_buffer, regex(user_input_v1), user_input_v2);
                ctd++;
            }
            
            system("cls");
            printf_s("The replacement has been completed.\nDo you want to continue with the replacement? (y/n)");
            cin >> user_cont;
            system("cls");
            if (user_cont != "y") {
                lp = 1;
                break;
            }
            else {
                ct++;
                continue;
            }
        }

        system("cls");
        ofs << "Unity AssetBundle Mainfest File\nShapaded by: UABMReplacer - version 1.0\n\nCopyright (C) 2021 - XyLe, All Rights Reserved.\n\n";
        if (ct != 0 && ctd % 2 == 0) {
            ofs << regex_buffer_v2;
        }
        else {
            ofs << regex_buffer_v1;
        }
        ofs.close();

        system("cls");
        return EXIT_SUCCESS;
    }
    default:
        system("cls");
        printf_s("Invalid option.");
        return EXIT_FAILURE;
    }
}

bool sortAll(char* targetpath, char* outputpath) {
    vector<double> data;
    ifstream fin(targetpath);
    if (!fin.is_open()) return 1;

    ofstream fout(outputpath);
    if (!fout.is_open()) return 1;

    data.assign(std::istream_iterator<double>(fin), std::istream_iterator<double>());
    sort(data.begin(), data.end());

    fout << "Unity AssetBundle Manifest File\nShapaded by: UABMReplacer - version 1.0\n\nCopyright (C) 2021 - XyLe, All Rights Reserved.\n\n";
    for (double item : data) {
        fout << item;
    }
    fout.close();
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf_s("UABMReplacer - Unity AssetBundle Mainfest shaping utility");
        printf_s("\nCopyright (C) 2021 - XyLe, All Rights Reserved.");
        printf_s("\n\nUsage: uabmr <INPUT_FILE> <OPTIONS> <OUTPUT_FILE>");
        printf_s("\n\n<INPUT_FILE>: Specifies the full path of the file to be formed.");
        printf_s("\n<OPTIONS>: Specify any options.");
        printf_s("\n<OUTPUT_FILE>: Specify the full path to save the file after it is formed.");
        printf_s("\n\nOPTIONS\n\n -d: Shaping the UABM in the usual way. (default)\n -s: Shaping UABM in a unique way (for advanced users)\n\n");
        return -1;
    }
    else
    {
        string strargv = argv[2];
        if (strargv.compare("-d") != 1) {
            if (get_ext(argv[1]).compare(".data") != 1) {
                bool ret = shapingUAB(0, argv[1], argv[3]);
                if (ret != 1) {
                    system("cls");
                    printf_s("All processes have completed successfully.");
                    return EXIT_SUCCESS;
                }
                else {
                    remove(argv[3]);
                    system("cls");
                    printf_s("No file will be output because an error has occurred.");
                    return EXIT_FAILURE;
                }
            }
            else if (get_ext(argv[1]).compare(".txt") != 1) {
                bool ret = shapingUAB(0, argv[1], argv[3]);
                if (ret != 1) {
                    system("cls");
                    printf_s("All processes have completed successfully.");
                    return EXIT_SUCCESS;
                }
                else {
                    remove(argv[3]);
                    system("cls");
                    printf_s("No file will be output because an error has occurred.");
                    return EXIT_FAILURE;
                }
            }
            else if (get_ext(argv[1]).compare(".unity3d") != 1) {
                bool ret = shapingUAB(0, argv[1], argv[3]);
                if (ret != 1) {
                    system("cls");
                    printf_s("All processes have completed successfully.");
                    return EXIT_SUCCESS;
                }
                else {
                    remove(argv[3]);
                    system("cls");
                    printf_s("No file will be output because an error has occurred.");
                    return EXIT_FAILURE;
                }
            }
            else {
                system("cls");
                printf_s("An unexpected error has occurred.");
                printf_s("\nThe file format of argument 1 is invalid.");
                printf_s("\nThe format must be one of the following: .txt, .data, .unity3d");
                return EXIT_FAILURE;
            }
        }
        else if (strargv.compare("-s") != 1) {
            if (get_ext(argv[1]).compare(".data") != 1) {
                bool ret = shapingUAB(1, argv[1], argv[3]);
                if (ret != 1) {
                    system("cls");
                    printf_s("All processes have completed successfully.");
                    return EXIT_SUCCESS;
                }
                else {
                    remove(argv[3]);
                    system("cls");
                    printf_s("No file will be output because an error has occurred.");
                    return EXIT_FAILURE;
                }
            }
            else if (get_ext(argv[1]).compare(".txt") != 1) {
                bool ret = shapingUAB(1, argv[1], argv[3]);
                if (ret != 1) {
                    system("cls");
                    printf_s("All processes have completed successfully.");
                    return EXIT_SUCCESS;
                }
                else {
                    remove(argv[3]);
                    system("cls");
                    printf_s("No file will be output because an error has occurred.");
                    return EXIT_FAILURE;
                }
            }
            else if (get_ext(argv[1]).compare(".unity3d") != 1) {
                bool ret = shapingUAB(1, argv[1], argv[3]);
                if (ret != 1) {
                    system("cls");
                    printf_s("All processes have completed successfully.");
                    return EXIT_SUCCESS;
                }
                else {
                    remove(argv[3]);
                    system("cls");
                    printf_s("No file will be output because an error has occurred.");
                    return EXIT_FAILURE;
                }
            }
            else {
                system("cls");
                printf_s("An unexpected error has occurred.");
                printf_s("\nThe file format of argument 1 is invalid.");
                printf_s("\nThe format must be one of the following: .txt, .data, .unity3d");
                return EXIT_FAILURE;
            }
        }
        else {
        printf_s("UABMReplacer - Unity AssetBundle Mainfest shaping utility");
        printf_s("\nCopyright (C) 2021 - XyLe, All Rights Reserved.");
        printf_s("\n\nUsage: uabmr <INPUT_FILE> <OPTIONS> <OUTPUT_FILE>");
        printf_s("\n\n<INPUT_FILE>: Specifies the full path of the file to be formed.");
        printf_s("\n<OPTIONS>: Specify any options.");
        printf_s("\n<OUTPUT_FILE>: Specify the full path to save the file after it is formed.");
        printf_s("\n\nOPTIONS\n\n -d: Shaping the UABM in the usual way. (default)\n -s: Shaping UABM in a unique way (for advanced users)\n\n");
            return -1;
        }
    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
