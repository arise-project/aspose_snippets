
//1. create empty pdf document
com.aspose.pdf.Document doc = new com.aspose.pdf.Document();

//2. add image to new pdf page        
//make list of files with images to merge
//add new page to pdf
//load image from stream with Aspose Imaging, it supports a lot of formats
//read image dimensions to pdf page rectangle
List<String> images = Arrays.asList(new String[]{"1.jpg", "2.jpg"});
for (String fs : images) {
    com.aspose.pdf.Page page = doc.getPages().add();        
    com.aspose.imaging.Image image = com.aspose.imaging.Image.load(fs);
    page.addImage(fs, new com.aspose.pdf.Rectangle(0, 0, image.getWidth() - 1, image.getHeight() - 1));
}

//3. save result pdf to file
doc.save("Merger_jpg_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
