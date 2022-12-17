package aspose_snippets.java;

public class Merger_pcl_pdf {
    public static void Execute() {
        String pathSource1 = "../../../../TestData/test.pcl";
        String pathSource2 = "../../../../TestData/Second/test.pcl";

        com.aspose.pdf.PclLoadOptions opt1 = new com.aspose.pdf.PclLoadOptions();
        //suspend not critical errors
        opt1.setSupressErrors(true);
        //pcl files can be parsed and loaded as Aspose Document
        com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document(pathSource1, opt1);

        com.aspose.pdf.PclLoadOptions opt2 = new com.aspose.pdf.PclLoadOptions();
        //suspend not critical errors
        opt2.setSupressErrors(true);
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
