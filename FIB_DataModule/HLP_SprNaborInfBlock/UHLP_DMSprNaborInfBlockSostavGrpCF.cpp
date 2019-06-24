#include "vcl.h"
#pragma hdrstop  
#include "UHLP_DMSprNaborInfBlockSostavGrpCF.h"   
#include "UHLP_DMSprNaborInfBlockSostavGrpImpl.h"  
#include "IHLP_DMSprNaborInfBlockSostavGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockSostavGrpCF::THLP_DMSprNaborInfBlockSostavGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockSostavGrpCF::~THLP_DMSprNaborInfBlockSostavGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_DMSprNaborInfBlockSostavGrpImpl * ob=new THLP_DMSprNaborInfBlockSostavGrpImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
