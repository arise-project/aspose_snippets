package aspose_snippets.java;

public class Merger_tex_pdf {
    public static void Execute() {
        var pathSource1 = "../../TestData/test.tex";
        var pathSource2 = "../../TestData/Second/test.tex";

        var opt1 = new com.aspose.pdf.TeXLoadOptions();

        //Cancels ligatures in all fonts
        opt1.setNoLigatures(false);
        //Rasterize scientific formulas to images
        opt1.setRasterizeFormulas(true);
        //Print parsing steps details to console output
        opt1.setShowTerminalOutput(true);

        //TeX files can be parsed and loaded as Aspose Document
        var firstDoc = new com.aspose.pdf.Document(pathSource1, opt1);

        var opt2 = new com.aspose.pdf.TeXLoadOptions();

        //Set ligatures in all fonts
        opt2.setNoLigatures(false);
        //Rasterize scientific formulas to images
        opt2.setRasterizeFormulas(true);
        //Print parsing steps details to console output
        opt2.setShowTerminalOutput(true);
        var secondDoc = new com.aspose.pdf.Document(pathSource2, opt2);

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
