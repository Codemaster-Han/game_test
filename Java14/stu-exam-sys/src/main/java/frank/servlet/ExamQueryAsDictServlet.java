package frank.servlet;

import frank.dao.ExamDAO;
import frank.model.Exam;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.List;

@WebServlet("/exam/queryAsDict")
public class ExamQueryAsDictServlet extends AbstractBaseServlet {
    @Override
    public Object process(HttpServletRequest req, HttpServletResponse resp) throws Exception {
        List<Exam> exams = ExamDAO.queryAsDict();
        return exams;
    }
}
