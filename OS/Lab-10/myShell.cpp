#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

void printShellStarting()
{
    char arr[50];
    getcwd(arr, sizeof(arr));
    cout << "@adminPc~" << arr << ">>> ";
}

vector<string> getArgs(string &input)
{
    vector<string> args;
    for (int i = 0; i < input.size(); i++)
    {
        string word = "";
        while (i < input.size() and ' ' != input[i])
        {
            word.push_back(input[i]);
            i++;
        }
        args.push_back(word);
    }
    return args;
}

void runWithoutArgsCommand(string cmd)
{
    pid_t q = fork();
    if (0 == q)
    {
        char ch[100] = "/bin/";
        for (int i = 0, j = 5; i < cmd.size(); i++, j++)
        {
            ch[j] = cmd[i];
        }
        execl(ch, "", NULL);
    }
    if (0 < q)
    {
        wait(NULL);
        return;
    }
}

void runWithArgsCommand(vector<string> cmd)
{
    pid_t q = fork();
    if (0 == q)
    {
        char ch[100] = "/bin/";
        for (int i = 0, j = 5; i < cmd.size(); i++, j++)
        {
            ch[j] = cmd[0][i];
        }
        execl(ch, cmd[0].c_str(), cmd[1].c_str(), NULL);
    }
    if (0 < q)
    {
        wait(NULL);
        return;
    }
}

int main()
{
    cout << endl;
    string input = "";
    vector<string> history;

    while (true)
    {
        printShellStarting();
        getline(cin, input);

        if ('\n' == input[0])
        {
            continue;
        }
        else
        {

            vector<string> args = getArgs(input);
            if ('\n' == input[0])
            {
                continue;
            }
            history.push_back(input);
            if (1 == args.size())
            {
                if ("exit" == args[0])
                {
                    return 0;
                }
                else
                {
                    runWithoutArgsCommand(input);
                }
            }
            else
            {
                runWithArgsCommand(args);
            }
        }
    }
    return 0;
}