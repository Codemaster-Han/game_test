package frank.filter;

/**
import com.fasterxml.jackson.databind.ObjectMapper;
import frank.model.Response;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;

@WebFilter("/*")
public class LoginFilter implements Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest req = (HttpServletRequest) request;
        HttpServletResponse res = (HttpServletResponse) response;
        String uri = req.getServletPath();
        HttpSession session = req.getSession(false);
        if(session == null) {//，没有登录
            //访问首页 /public/page/main.html，没有登录重定向到登陆页面
            if ("/public/page/main.html".equals(uri)) {
                String schema = req.getScheme();//http
                String host = req.getServerName();//服务器ip或域名
                int port = req.getServerPort();//服务器端口号
                String contextPath = req.getContextPath();
                String basePath = schema + "://" + host + ":" + port + contextPath;
                res.sendRedirect(basePath + "/public/index.html");
                return;
                //访问后台的敏感资源，servlet的敏感服务，返回json数据
            } else if (!"/login.html".equals(uri) && !uri.startsWith("/public/") && !uri.startsWith("/static/")
                    && !"/user/login".equals(uri)) {//访问敏感资源
                req.setCharacterEncoding("UTF-8");//针对请求体设置编码，注意对url中的请求数据无效
                res.setCharacterEncoding("UTF-8");//针对响应体设置编码
                res.setContentType("application/json");//设置响应的数据格式：响应头Content-Type告诉浏览器怎么解析
                Response r = Response.error("301", "未被授权的访问");
                PrintWriter pw = res.getWriter();
                ObjectMapper mapper = new ObjectMapper();
                mapper.setDateFormat(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss"));
                String json = mapper.writeValueAsString(r);
                pw.println(json);
                pw.flush();
                return;
            }
        }
        chain.doFilter(request, response);
    }

    @Override
    public void destroy() {

    }
}

*/

import javax.servlet.*;
        import javax.servlet.annotation.WebFilter;
        import javax.servlet.http.HttpServletRequest;
        import javax.servlet.http.HttpServletResponse;
        import javax.servlet.http.HttpSession;
        import java.io.IOException;

@WebFilter("/*")
public class LoginFilter implements Filter {
    //初始化方法  接收一个FilterConfig类型的参数 该参数是对Filter的一些配置
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    //过滤方法 主要是对request和response进行一些处理，然后交给下一个过滤器或Servlet处理
    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest req = (HttpServletRequest) request;
        HttpServletResponse resp = (HttpServletResponse) response;
        /**
         * 判断是否是敏感资源
         * 如果是，获取session
         * 获取不到的话，那么重定向到登录页面
         */
        String uri = req.getServletPath();
        if(!uri.startsWith("/public/") && !uri.startsWith("/static/") && !uri.equals("/user/login")){
            //获取session
            HttpSession session = req.getSession(false);
            //没有登录
            if(session == null){
                //resp.sendRedirect("/ses/public/index.html");
                String scheme = req.getScheme();//http
                String host = req.getServerName();//服务器ip
                int port = req.getServerPort();//服务器端口
                String contextPath = req.getContextPath();//项目部署名
                String baseUrl = scheme + "://" + host + ":" + port + contextPath;
                resp.sendRedirect(baseUrl + "/public/index.html");
                return;
            }
        }
        //非敏感资源或者敏感资源登录之后，继续调用后边的过滤器
        chain.doFilter(request, response);
    }

    @Override
    public void destroy() {

    }
}
