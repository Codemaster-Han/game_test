package frank.servlet;

import frank.dao.ExamRecordDAO;
import frank.model.ExamRecord;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/examRecord/queryById")
public class ExamRecordQueryByIdServlet extends AbstractBaseServlet {
    @Override
    public Object process(HttpServletRequest req, HttpServletResponse resp) throws Exception {
        //获取学生借阅信息id
        String id = req.getParameter("id");
        ExamRecord record = ExamRecordDAO.queryById(Integer.parseInt(id));
        return record;
    }
}
