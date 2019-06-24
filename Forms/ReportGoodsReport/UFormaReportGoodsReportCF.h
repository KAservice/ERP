#ifndef UFormaReportGoodsReportCFH                  
#define UFormaReportGoodsReportCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportGoodsReportCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportGoodsReportCF();                                                           
   ~TFormaReportGoodsReportCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
