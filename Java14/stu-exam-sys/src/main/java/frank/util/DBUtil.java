package frank.util;
//jdbc配置连接
import com.mysql.jdbc.jdbc2.optional.MysqlDataSource;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DBUtil {

    private static volatile DataSource DATA_SOURCE;
    private static final String URL = "jdbc:mysql://localhost:3306/stu_exam";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "hyshagua5-1";  //要输入自己的数据库用户名和密码，否则会一直报错

    private DBUtil(){}

    private static DataSource getDataSource(){
        if(DATA_SOURCE == null){
            synchronized (DBUtil.class){
                if(DATA_SOURCE == null){
                    DATA_SOURCE = new MysqlDataSource();
                    ((MysqlDataSource) DATA_SOURCE).setUrl(URL);
                    ((MysqlDataSource) DATA_SOURCE).setUser(USERNAME);
                    ((MysqlDataSource) DATA_SOURCE).setPassword(PASSWORD);
                }
            }
        }
        return DATA_SOURCE;
    }

    public static Connection getConnection(){
        try {
            return getDataSource().getConnection();
        } catch (SQLException e) {
            throw new RuntimeException("获取数据库连接失败", e);
        }
    }

    public static void close(Connection c, Statement s){
        close(c, s, null);
    }

    public static void close(Connection c, Statement s, ResultSet r){
        try {
            if(r != null)
                r.close();
            if(s != null)
                s.close();
            if(c != null)
                c.close();
        } catch (SQLException e) {
            throw new RuntimeException("释放数据库资源出错", e);
        }
    }
}
