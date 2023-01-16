
doc = new com.aspose.pdf.Document("1.pdf");

if(doc.getPages().get_Item(1).getArtifacts().get_Item(1).getSubtype() == com.aspose.pdf.Artifact.ArtifactSubtype.Watermark)
    doc.getPages().get_Item(1).getArtifacts().delete(doc.getPages().get_Item(1).getArtifacts().get_Item(1));

//save result pdf to file
doc.save("remove_watermark.pdf", com.aspose.pdf.SaveFormat.Pdf);
