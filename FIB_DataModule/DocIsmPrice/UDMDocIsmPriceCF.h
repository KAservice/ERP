#ifndef UDMDocIsmPriceCFH                  
#define UDMDocIsmPriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocIsmPriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocIsmPriceCF();                                                           
   ~TDMDocIsmPriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
