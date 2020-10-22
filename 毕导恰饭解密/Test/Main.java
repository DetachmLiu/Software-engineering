package Test;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    /**
     * 由视频中毕导的提示 "COCBKPI" 对应 "AMAZING"
     * 可知此文本使用了凯撒加密，且易得明文为密文 -2 得到
     * eg ： C - 2 = A      M - 2 = O ...
     * 故直接暴力遍历即可
     * @param article 文本
     */
    private static void decodeText(List<String> article) throws IOException {
        PrintWriter writer = new PrintWriter("decode.txt");
        System.out.println((int)'A' + " " + (int)'Z');
        // 遍历破译 + 输出
        System.out.println((char)('A' + 24));
        for (String line : article) {
            StringBuilder sb = new StringBuilder();
            for (char ch : line.toCharArray()) {
                // 'A' -> 'Y'    'B' -> 'Z'
                sb.append((char)(ch - 2 >= 'A' ? ch - 2 : ch + 24));
            }
            writer.println(sb);
        }

        // 使用完后关闭输出流~
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("codes.txt"));

        // 从 code.txt 中读取文字
        List<String> article = new ArrayList<>();
        while (in.hasNextLine()) {
            article.add(in.nextLine());
        }

        // 解密函数
        decodeText(article);
        in.close();
    }
}

