package aspose_snippets.java;

import java.util.Arrays;
import java.util.List;

public class Merger_jpg_pdf {
    public static void Execute() {
        String pathSource1 = "../../TestData/test.jpg";
        String pathSource2 = "../../TestData/Second/test.jpg";

        //create empty pdf document
        com.aspose.pdf.Document doc = new com.aspose.pdf.Document();

        //set less memory usage with unload instead of fast performance
        doc.setEnableObjectUnload(true);

        //make list of files with images to merge
        List<String> images = Arrays.asList(new String[]{pathSource1, pathSource2});

        for (String fs : images) {
            //add new page to pdf
            com.aspose.pdf.Page page = doc.getPages().add();

            //setup page size to be A4
            page.setPageSize(
                    com.aspose.pdf.PageSize.getA4().getWidth(),
                    com.aspose.pdf.PageSize.getA4().getHeight());

            com.aspose.pdf.Rectangle rect;

            //load image from stream, it supports a lot of formats
            com.aspose.imaging.Image image = com.aspose.imaging.Image.load(fs);
            //read image dimensions to pdf page rectangle
            rect = new com.aspose.pdf.Rectangle(0, 0, image.getWidth() - 1, image.getHeight() - 1);

            //add image to new pdf page
            page.addImage(fs, rect);
        }

        //save result pdf to file
        doc.save("Merger_jpg_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}
