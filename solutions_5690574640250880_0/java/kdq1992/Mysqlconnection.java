package com.db;

import java.sql.Connection;
import java.sql.DriverManager;

public class Mysqlconnection {
	// ����
	// �������ݿ�����ĳ���������
	// ���ݿ���������
	private final String DBDRIVER = "com.mysql.jdbc.Driver";
	// ���ݿ����ӵ�ַ
	private final String DBURL = "jdbc:mysql://localhost:3306/xgnews";
	// ���ݿ��û���
	private final String DBUSER = "root";
	// ���ݿ���������
	private final String DBPASSWORD = "xg@adminv587";
	// ����һ�����ݿ����Ӷ���
	private Connection conn = null;
	// �ڹ��췽��֮���������ݿ�
	public Mysqlconnection() {
		try {
			// ������������
			Class.forName(DBDRIVER);
			// �������ݿ�
			conn = DriverManager.getConnection(DBURL, DBUSER, DBPASSWORD);
		} catch (Exception e) {
			System.out.println(e);
		}
	}
	// ����һ�����ݿ�����
	public Connection getConnection() {
		// / �������Ӷ���
		return this.conn;
	}
	// �ر����ݿ�����
	public void close() {
		try {
			this.conn.close();
		} catch (Exception e) {
		}
	}
}