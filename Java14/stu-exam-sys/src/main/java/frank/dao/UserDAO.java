package frank.dao;

import frank.model.User;
import frank.util.DBUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class UserDAO {

    public static User query(User user) {
        User queryUser = null;
        Connection c = null;
        PreparedStatement ps = null;
        ResultSet rs = null;

        try {
            c = DBUtil.getConnection();
            String sql = "select id,nickname from user where username=? and password=?";
            ps = c.prepareStatement(sql);
            ps.setString(1, user.getUsername());
            ps.setString(2, user.getPassword());
            rs = ps.executeQuery();
            while(rs.next()){
                queryUser = user;
                queryUser.setId(rs.getInt("id"));
                queryUser.setNickname(rs.getString("nickname"));
            }
        } catch (Exception e) {
            throw new RuntimeException("用户登录操作出错", e);
        } finally {
            DBUtil.close(c, ps, rs);
        }
        return queryUser;
    }
}
