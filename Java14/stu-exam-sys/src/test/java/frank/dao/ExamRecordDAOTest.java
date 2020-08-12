package frank.dao;

import frank.model.ExamRecord;
import org.junit.After;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import java.math.BigDecimal;
import java.util.Date;

import static org.junit.Assert.*;

public class ExamRecordDAOTest {


    /**
     * 其他的一些注解
    @After  //单元测试做完以后的清理工作
    @Before  //初始化
    @Ignore  //忽略该方法
     */

    @Test
    public void queryById() {
        ExamRecordDAO examRecordDAO=new ExamRecordDAO();
        ExamRecord examRecord01= new ExamRecord();
        System.out.println("查询结果="+examRecordDAO.queryById(15));
    }

    @Test
    public void insert() {
        //创建一个实体对象
        ExamRecordDAO examRecordDAO=new ExamRecordDAO();
        ExamRecord examRecord01= new ExamRecord();
        examRecord01.setId(01);
        examRecord01.setScore(BigDecimal.valueOf(88));
        examRecord01.setStudentId(01);
        examRecord01.setExamId(01);
        examRecord01.setExamRecordDesc("成绩不错，继续加油");
        Date time= new java.sql.Date(new java.util.Date().getTime());
        examRecord01.setCreateTime(time);
        examRecordDAO.insert(examRecord01);//插入数据
        System.out.println("examRecord01_id="+examRecord01.getScore());//88
    }

    @Test
    public void update() {
        ExamRecordDAO examRecordDAO=new ExamRecordDAO();
        ExamRecord examRecord01= new ExamRecord();
        examRecord01.setId(20);
        examRecord01.setExamId(04);
        examRecord01.setStudentId(01);
        examRecord01.setScore(BigDecimal.valueOf(99));
        examRecordDAO.update(examRecord01);
        System.out.println("examRecord01_score="+examRecord01.getScore());
    }

    @Test
    public void delete() {
        ExamRecordDAO examRecordDAO=new ExamRecordDAO();
        ExamRecord examRecord01= new ExamRecord();
        String[] delete_id={"18","20"};
        examRecordDAO.delete(delete_id);
        System.out.println("删除成功");
    }
}