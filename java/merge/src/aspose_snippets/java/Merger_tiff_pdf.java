package aspose_snippets.java;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

import com.aspose.imaging.Color;

public class Merger_tiff_pdf {
    public static void Execute() throws FileNotFoundException {
        String pathSource1 = "../../TestData/test.tiff";
        String pathSource2 = "../../TestData/Second/test.tiff";

        //Load tiff to Aspose image
        com.aspose.imaging.fileformats.tiff.TiffImage multiImage1 = (com.aspose.imaging.fileformats.tiff.TiffImage) com.aspose.imaging.Image.load(pathSource1);
        com.aspose.imaging.fileformats.tiff.TiffImage multiImage2 = (com.aspose.imaging.fileformats.tiff.TiffImage) com.aspose.imaging.Image.load(pathSource2);

        //make list of tiff images to merge
        com.aspose.imaging.fileformats.tiff.TiffImage[] images = new com.aspose.imaging.fileformats.tiff.TiffImage[]{multiImage1, multiImage2};

        //create empty pdf document
        com.aspose.pdf.Document outputDoc = new com.aspose.pdf.Document();

		int index = 1;
        for (com.aspose.imaging.fileformats.tiff.TiffImage multiImage : images) {
            //iterate through tiff frames
            for (com.aspose.imaging.fileformats.tiff.TiffFrame tiffFrame : multiImage.getFrames()) {
                //set active frame to work with
                multiImage.setActiveFrame(tiffFrame);

                //load bitmap from a frame
                Color[] pixels = multiImage.loadPixels(tiffFrame.getBounds());

                com.aspose.imaging.Source ms = new com.aspose.imaging.sources.FileCreateSource(
                        String.valueOf(index) + "temp.tiff",
                        false); //preserve image on the disk

                //create image savesource to a stream
                com.aspose.imaging.imageoptions.JpegOptions createOptions = new com.aspose.imaging.imageoptions.JpegOptions();
                createOptions.setSource(ms);

                //create empty image with width and hight
                com.aspose.imaging.fileformats.jpeg.JpegImage tiffImage = (com.aspose.imaging.fileformats.jpeg.JpegImage)
                        com.aspose.imaging.Image.create(createOptions, tiffFrame.getWidth(), tiffFrame.getHeight());
                //set frame bounds to save to bitmap
                tiffImage.savePixels(tiffFrame.getBounds(), pixels);
                //save frame bitmap to stream
                tiffImage.save();

                //add new page to document
                com.aspose.pdf.Page page = outputDoc.getPages().add();

                page.getPageInfo().getMargin().setBottom(0);
                page.getPageInfo().getMargin().setTop(0);
                page.getPageInfo().getMargin().setLeft(0);
                page.getPageInfo().getMargin().setRight(0);
                page.getPageInfo().setWidth(tiffFrame.getWidth());
                page.getPageInfo().setHeight(tiffFrame.getHeight());

                //create new image into document
                com.aspose.pdf.Image image = new com.aspose.pdf.Image();
                //set image source to memory stream
                image.setImageStream(new FileInputStream(String.valueOf(index) + "temp.tiff"));

                //add document image to specific page
                page.getParagraphs().add(image);
            }
        }

        //save result pdf to file
        outputDoc.save("Merger_tiff_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}
