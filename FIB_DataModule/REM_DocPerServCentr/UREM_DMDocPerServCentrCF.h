#ifndef UREM_DMDocPerServCentrCFH                  
#define UREM_DMDocPerServCentrCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocPerServCentrCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocPerServCentrCF();                                                           
   ~TREM_DMDocPerServCentrCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
