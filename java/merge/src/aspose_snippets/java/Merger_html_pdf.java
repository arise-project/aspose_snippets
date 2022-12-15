package aspose_snippets.java;

public class Merger_html_pdf {
    public static void Execute() {
        String pathSource1 = "../../TestData/test.html";
        String pathSource2 = "../../TestData/Second/test.html";

        com.aspose.pdf.HtmlLoadOptions opt1 = new com.aspose.pdf.HtmlLoadOptions();

        //set html encodyng
        opt1.setInputEncoding("UTF-8");
        //render all html to single large pdf page
        opt1.setRenderToSinglePage(true);

        //html files can be parsed and loaded as Aspose Document
        com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document(pathSource1, opt1);

        com.aspose.pdf.HtmlLoadOptions opt2 = new com.aspose.pdf.HtmlLoadOptions();
        //set html encodyng
        opt2.setInputEncoding("UTF-8");
        //split html content to pdf pages
        opt2.setRenderToSinglePage(false);

        com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document(pathSource2, opt2);

        //create empty pdf document
        com.aspose.pdf.Document outputDoc = new com.aspose.pdf.Document();

        //set less memory usage with unload instead of fast performance
        outputDoc.setEnableObjectUnload(true);

        for (com.aspose.pdf.Page page : firstDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        for (com.aspose.pdf.Page page : secondDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        //save result pdf to file
        outputDoc.save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}
