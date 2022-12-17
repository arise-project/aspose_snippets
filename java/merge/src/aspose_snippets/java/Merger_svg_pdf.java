package aspose_snippets.java;

public class Merger_svg_pdf {
    public static void Execute() {
        var pathSource1 = "../../TestData/test.svg";
        var pathSource2 = "../../TestData/Second/test.svg";

        //Adust pdf page size to svg size
        var opt1 = new com.aspose.pdf.SvgLoadOptions();
        opt1.setAdjustPageSize(true);
        //SVG files can be parsed and loaded as Aspose Document
        var firstDoc = new com.aspose.pdf.Document(pathSource1, opt1);

        //Use default pdf page size
        var opt2 = new com.aspose.pdf.SvgLoadOptions();
        opt1.setAdjustPageSize(false);
        var secondDoc = new com.aspose.pdf.Document(pathSource2, opt2);

        //create empty pdf document
        var outputDoc = new com.aspose.pdf.Document();

        //set less memory usage with unload instead of fast performance
        outputDoc.setEnableObjectUnload(true);

        for (var page : firstDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        for (var page : secondDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        //save result pdf to file
        outputDoc.save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}
