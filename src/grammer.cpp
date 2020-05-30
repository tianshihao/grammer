﻿#include "grammer.h"

Grammer::Grammer()
{
    std::cout << "This is a grammer" << std::endl;
}

Grammer::Grammer(std::string inputText)
{
    ParseText(inputText);
}

void Grammer::SetType(int type)
{
    m_type = type;
}

int Grammer::GetType()
{
    return m_type;
}

void Grammer::ParseText(std::string inputText)
{
    // 向输入文本串末尾加换行符
    inputText = inputText + "\n";

    while (!inputText.empty())
    {
        int index = 0;
        Production tempProduction;
        Expression tempExpression;

        // 扫描产生式左部
        for (int i = 0;; ++i)
        {
            // 检查箭头 "->"
            if (inputText[i] == '-')
            {
                // 防止越界
                if ((i + 1) <= (int)inputText.length() - 1)
                {
                    if (inputText[i + i] == '>')
                    {
                        index = i + 1 + 1;
                        break;
                    }
                }
            }

            // 不是箭头
            tempExpression.PushBack(inputText[i]);
        }

        inputText.erase(0, index);
        tempProduction.SetLeftPart(tempExpression);
        tempExpression.Clear();

        // 扫描产生式右部
        for (int i = 0; (inputText[i] != '\n') && (i < (int)inputText.length()); ++i, index = i)
        {
            // 找到一个表达式
            if (inputText[i] == '|')
            {
                tempProduction.SetRightPart(tempExpression);
                tempExpression.Clear();
                inputText.erase(0, i + 1);
                i = -1;
                continue;
            }

            tempExpression.PushBack(inputText[i]);
        }
        // tempExpression.PushBack(inputText[0]);
        tempProduction.SetRightPart(tempExpression);
        // inputText.clear();
        inputText.erase(0, index + 1);

        // 找到一个产生式
        m_productionSet.push_back(tempProduction);
    }

    m_start = m_productionSet[0].GetLeftPart();

    Print();
}

void Grammer::Print()
{
    std::cout << "grammer" << std::endl;
    std::cout << "start symbol: " << m_start.GetExpression() << std::endl;
    std::cout << "production" << std::endl;

    for (int i = 0; i < (int)m_productionSet.size(); ++i)
    {
        std::cout << "production " << i + 1 << ": ";
        std::cout << m_productionSet[i].GetLeftPart().GetExpression() << " -> ";

        for (int j = 0; j < (int)m_productionSet[i].GetRightPart().size(); ++j)
        {
            std::cout << m_productionSet[i].GetRightPart()[j].GetExpression();
            if (j != (int)m_productionSet[i].GetRightPart().size() - 1)
            {
                std::cout << " | ";
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }
}