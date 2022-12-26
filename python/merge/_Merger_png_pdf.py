from Aspose.Imaging import Rectangle
from Aspose.Imaging import Image
from aspose.pdf import SaveFormat
from aspose.pdf import PageSize
from aspose.pdf import Document
import clr

aspose_pdf = clr.addReference("../../lib/Aspose.PDF.dll")
aspose_imaging = clr.addReference("../../lib/Aspose.Imaging.dll")

class png_to_pdf(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec():
        path_source1 = "../../TestData/test.png"
        path_source2 = "../../TestData/Second/test.png"

        # create empty pdf document
        doc = Document

        # set less memory usage with unload instead of fast performance
        doc.enable_object_unload = True

        # make list of files with images to merge
        images = [path_source1, path_source2]

        for fs in images:
            # add new page to pdf
            page = doc.pages.add()

            # setup page size to be A4
            page.SetPageSize(PageSize.a4.width, PageSize.a4.height)

            # load image from stream, it supports a lot of formats
            image = Image.Load(fs)
            # read image dimensions to pdf page rectangle
            rect = Rectangle(0, 0, image.width - 1, image.height - 1)

            # add image to new pdf page
            page.addImage(fs, rect)

        # save result pdf to file
        doc.save("test.pdf", SaveFormat.Pdf)
