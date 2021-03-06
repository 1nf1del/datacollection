/*
 * FAE, Feinno App Engine
 *  
 * Create by gaolei Apr 13, 2013
 * 
 * Copyright (c) 2013 北京新媒传信科技有限公司
 */
package round1b;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * {在这里补充类的功能说明}
 * 
 * @author 高磊 gaolei@feinno.com
 */
public class A
{	
	public static void main(String[] args) throws Exception
	{
		A instance = new A("A-small-attempt0.in");
		instance.slove();
		instance.writer.close();
	}
	
	private Scanner scaner;
	private PrintWriter writer; 
	
	public A(String inf) throws Exception
	{
		scaner = new Scanner(new FileInputStream(inf));
		writer = new PrintWriter(new FileOutputStream(inf + ".out"));		
	}
	
	private void slove()
	{
		int caseCount = scaner.nextInt();
		for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++) {
			int a = scaner.nextInt();
			int n = scaner.nextInt();
			ArrayList<Integer> list = new ArrayList<Integer>();
			
			for (int i = 0; i < n; i++) {
				list.add(scaner.nextInt());
			}			
			Collections.sort(list);
			
			int result = slove(a, list, 0, n);
			
			
			System.out.printf("Case #%d: %s\n", caseNumber, result);
			writer.printf("Case #%d: %s\n", caseNumber, result);
		}
	}
	
	private int slove(int sum, List<Integer> list, int begin, int end)
	{
		for (int i = begin; i < end; i++) {
			if (list.get(i) < sum) {
				sum += list.get(i);
				continue;
			} else {
				sum = sum + sum - 1;
				int left;
				int right = end - i;
				if (sum > 1) { 
					left = slove(sum, list, i, end) + 1;
				} else {
					return right;
				}
				return left < right ? left : right;
			}
		}
		return 0;
	}
}
